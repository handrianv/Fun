/*
    https://acm.timus.ru/problem.aspx?space=1&num=1320
    What a small world, this problem just appeared in a recent CF contest! https://codeforces.com/contest/1519/problem/E
    Or here is a more similar version https://codeforces.com/problemset/problem/858/F but it's still harder (needs to print the edges).

    First let's parse the problem: can we cover the entire graph with paths of length 2? 
    
    Hint:
    For some undirected graph problems, it's often easier to think in term of DFS Tree https://codeforces.com/blog/entry/68138.
    Consider only the tree (ignore cycle edges), how would you solve the problem? Now add the cycle edges, what does this change?
    Hint within hint: Try to solve it for each subtree, starting from the lowest (farthest from root).

    Solution:
    For each connected component, the answer is yes iff number of edges is even.

    Proof:
    First observe that since the paths are of length 2, we can have at most floor(n/2) paths. 
    So if n odd the answer is NO, because we'll have at least one unused edge. Otherwise, we can always use all the edges.

    Let R be the root of the entire tree.

    We'll prove it by showing an actual construction. Let's solve the problem on a tree first, starting from the lowest non-leaf subtree.
    -. If the number of edges is even, it's clear we can do a full cover.
    -. Otherwise, there will be exactly one unpaired edge. But if the root of current subtree is not R, then we can make a path of length 2 (unpaired child - root - parent[root]). 
    After that we mark this root as "unavailable" when solving the problem on its parent, meaning the edge (root - parent[root]) can't be used to make another path.

    In pseudocode:
    Solve(root)
    {
        int available_edges = 0;
        for(all child : root)
        {
            Solve(child)
            if(edge (child-root) is available) ++available_edges;
        }
        pair all available edges
        
        if(available edges == 1 AND this is not R) 
            pair the remaining edge with edge (root, par[root])
            mark this root unavailable
    }

    This construction guarantees that all edges will be used except if there is an unpaired edge in R. 
    But this can't happen when total number of edges is even. To see this, imagine we remove all edges that have been used. Since each
    path is of length 2, we've removed an even number of edges, and the total number of edges is still even. If we do this procedure on R,
    then we've deleted all edges in the tree except the unpaired edge.
    For any root we can have at most one unpaired edge. But if there is such an edge on R, then the total number of edges is odd, a contradiction.

    What about cycle edges? Notice that in above construction, only the number of child in each subtree matters, the "type" of edges itself is irrelevant.
    So we can imagine that cycle edges are directed from low height (closer to root) to high height. Then we can just treat the endpoint of the cycle like any other
    child.
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

const int MAXN = 1005;
vector<int> graph[MAXN];
int color[MAXN];

// Return number of edges
int DFS(int curr, int par)
{
    color[curr] = 1;
    int edge_cnt = 0;
    for(const auto& child : graph[curr])
    {
        if(child == par) continue;
        if(color[child] != 1)
        {
            ++edge_cnt;
            if(color[child] == 0) edge_cnt += DFS(child, curr);
        }
    }
    color[curr] = 2;
    return edge_cnt;
}

void Solve(const int &tc = 1)
{
    int a;
    while(cin >> a)
    {
        int b;
        cin >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= 1000; ++i)
    {
        if(color[i] == 0)
        {
            int edge_cnt = DFS(i, i);
            //cout << "[DEBUG] edge_cnt of " << i << " = " << edge_cnt << "\n";
            if(edge_cnt % 2 != 0)
            {
                cout << "0\n";
                return;
            }
        }
    }
    cout << "1\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(9);

    int tc = 1;
    //cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        Solve(i);
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