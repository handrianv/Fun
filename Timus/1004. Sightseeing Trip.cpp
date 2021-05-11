/*
    https://acm.timus.ru/problem.aspx?space=1&num=1004  
    Find the shortest simple cycle in a weighted undirected graph. This is also called the girth of the graph.

    Approach #1
    For each edge u-v, we can find the shortest cycle containing this edge by finding the shortest path from u to v but ignoring this edge.
    We do this for every edge so complexity is O(M * Dijkstra).
    But it seems that this problem has been updated, so this approach causes TLE.

    Approach #2
    Since N is small, instead of computing girth for every edge, we can compute girth for every vertices.
    Do Dijkstra from each vertex R and consider the shortest path tree. All edges (u, v) not in the tree will create a cycle and if LCA(u, v) = R,
    then it's the shortest simple cycle containing u, c, and R. 
    Time complexity: O(N * Dijkstra * LCA). Depending on how the LCA is immplemented, it could be log(N). Seems it's enough to pass.

    Approach #3
    But the most interesting approach is using Floyd-Warshall. Credits to this comment for the idea https://codeforces.com/blog/entry/53387?#comment-374176.
    The first thought would probably be: do FW, then dist[i][i] is the girth containing i. But this will not work, because edges are bidirectional.
    So we might take edge (i, j) twice back and forth, creating a not-simple cycle.

    Instead, consider three adjacent nodes in the cycle i, j, k. Then the shortest simple cycle can be decomposed into sum of:
    1. Shortest path i-j without using k
    2. Edge j-k
    3. Edge k-i

    But (1) is exactly what FW is doing! Before the k'th iteration finish, dist[i][j] contains the shortest path from i to j without using nodes {k, k+1, ..., n}
    So to find the girth, we will find the minimum of (dist[i][j] + weight[i][k] + weight[j][k]) amongst all n iterations.

    This seems intuitively true, but fully convincing yourself it works is tricky. Here are some points that is not obviously true at first glance: 
    1. When we consider shortest_path(i, j) before the k'th iteration, it's true that the shortest path does not contain node k. But shortest_path(i, j)
       might not be the shortest among all path that does not contain node k. For example, consider that the true shortest_path(i, j) without node k is i-(k+1)-j.
    2. Why (dist[i][j] + weight[i][k] + weight[j][k]) instead of (dist[i][j] + dist[i][k] + dist[j][k])? Why i-k-j must be adjacent?
    
    Answer 
    1. The algorithm still works. It's just that the true girth will be found NOT on the k'th iteration, but instead on the (k+1)-th iteration.
       In general, let M be the largest node id in the girth, and i-M-j be the three adjacent nodes. Then we'll find the girth on the M'th iteration.
       In this case, dist[i][j] does not contain node M yet, but we know that the true shortest_path(i, j) without M must not contain node id > M. Otherwise we
       can make a shorter cycle, contradicting the fact that this is a girth and the fact that M is the largest node id in the girth.

    2. dist[i][k] might pass through node j, making the cycle not simple.
*/

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <bitset>
#include <random>
#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define EPS 1e-9
#define CeilDiv(a, b) ((a + b - 1) / b)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void Backtrack(const int& from, const int& to, const int& k, const vector<vector<vector<char>>>& intermediate, vector<int>& path)
{
    //cout << "[DEBUG] Backtrack from = " << from << " to = " << to << " k = " << k << "\n";
    if(k < 0)
    {
        path.push_back(from+1);
        return;
    }

    if(intermediate[from][to][k])
    {
        Backtrack(from, k, k-1, intermediate, path);
        Backtrack(k, to, k-1, intermediate, path);
    }
    else
    {
        Backtrack(from, to, k-1, intermediate, path);
    }
}

// TODO REVERT CONTRACT
void Solve(const int &n)
{
    int m;
    cin >> m;
    const int INF = 1e8;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<vector<char>>> intermediate(n, vector<vector<char>>(n, vector<char>(n, false)));
    vector<vector<int>> adj_mat = dist;
    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        dist[a][b] = dist[b][a] = min(w, dist[a][b]);
        adj_mat[a][b] = adj_mat[b][a] = dist[a][b];
    }
    
    int girth = INF, girth_from = INF, girth_to = INF, girth_inter = INF;
    for(int k = 0; k < n; ++k)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i != j && i != k && j != k)
                {
                    //cout << "[DEBUG] Cycle from " << i << " to " << j << " mid " << k << " = " << dist[i][j] + adj_mat[i][k] + adj_mat[k][j] << "\n";
                    
                    // Note: dist[i][j] + dist[i][k] + dist[k][j] doesn't work
                    int new_girth = dist[i][j] + adj_mat[i][k] + adj_mat[k][j];
                    if(new_girth < girth)
                    {
                        girth = new_girth;
                        girth_from = i; girth_to = j; girth_inter = k;
                    }
                }

                int new_dist = dist[i][k] + dist[k][j];
                if(new_dist < dist[i][j])
                {
                    dist[i][j] = new_dist;
                    intermediate[i][j][k] = true;
                }
            }
        }
    }

    if(girth == INF)
    {
        cout << "No solution.\n";
        return;
    }

    //cout << "[DEBUG] Girth = " << girth << " girth_from = " << girth_from << " girth_to = " << girth_to << " girth_inter = " << girth_inter << "\n";
    vector<int> path;
    Backtrack(girth_from, girth_to, girth_inter-1, intermediate, path);
    path.push_back(girth_to+1);
    path.push_back(girth_inter+1);

    for(int i = 0; i < (int)path.size(); ++i)
    {
        cout << path[i] << " \n"[i+1 == (int)path.size()];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(9);

    // int tc = 1;
    // cin >> tc;
    // for (int i = 1; i <= tc; ++i)
    // {
    //     Solve(i);
    // }

    int n;
    cin >> n;
    while(n != -1)
    {
        Solve(n);
        cin >> n;
    }
    return 0;
}

/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
multiset count IS NOT O(LOG N)!! It's also linear in the number of matches! Costed TLE in systest :(
setprecision for doubles!! Costed me half a day of life!!
*/