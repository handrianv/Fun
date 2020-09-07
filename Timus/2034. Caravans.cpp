/*
    Do BFS with a pair of state (shortest distance to this node, out of all shortest path the maximum distance that robber needs to take).
    For transition take minimum of the first state and maximum of the second state.
    To do transition quickly, precompute distance from robber to all other nodes.
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
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e5+5;
vector<int> graph[MAXN];
int val[MAXN]; // Dist from r
int n, m, s, f, r;

void BFS1()
{
    vector<int> dist(n+5, 1e9);
    queue<int> que;
    que.push(r);
    dist[r] = 0;

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();
        val[curr] = dist[curr]; 

        for(auto& v : graph[curr])
        {
            if(dist[curr] + 1 < dist[v])
            {
                dist[v] = dist[curr] + 1;
                que.push(v);
            }
        }
    }
}

int BFS2()
{
    vector<pi> dist(n+5, {1e9, 1e9}); // {shortest dist, dist from r}
    queue<int> que;
    que.push(s);
    dist[s] = {0, val[s]};

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();
        if(curr == f) return dist[curr].second;

        for(auto& v : graph[curr])
        {
            int nextSecond = min(dist[curr].second, val[v]);
            if(dist[curr].first + 1 < dist[v].first)
            {
                dist[v] = {dist[curr].first + 1, nextSecond};
                que.push(v);
            }
            else if(dist[curr].first + 1 == dist[v].first && nextSecond > dist[v].second)
            {
                dist[v] = {dist[curr].first+1, nextSecond};
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> s >> f >> r;

    BFS1();
    cout << BFS2() << "\n";
    return 0;
}
 
/*
 
*/  