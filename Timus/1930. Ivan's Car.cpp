/*
    Classic 0-1 BFS problem. Store direction to know whether an edge costs 0 or 1.
    0-1 BFS tutorial: http://codeforces.com/blog/entry/22276
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e4+5;
vector<pi> graph[MAXN]; // {Up/down, node}
int dist[MAXN][2];
int n, m, source, dest;

int BFS()
{
    for(int i = 1; i <= n; ++i) dist[i][0] = dist[i][1] = MAXN;
    dist[source][0] = dist[source][1] = 0;
    deque<pi> que;
    que.push_back({0, source}); que.push_back({1, source});

    while(!que.empty())
    {
        pi curr = que.front();
        que.pop_front();
        int currNode = curr.second, currType = curr.first;
        if(currNode == dest) return dist[currNode][currType];

        for(auto& edge : graph[currNode])
        {
            int w = (currType != edge.first);
            int nxtDist = dist[currNode][currType] + w;

            if(nxtDist < dist[edge.second][edge.first])
            {
                dist[edge.second][edge.first] = nxtDist;
                (w == 0) ? que.push_front(edge) : que.push_back(edge);
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
        graph[a].push_back({1, b});
        graph[b].push_back({0, a});
    }
    cin >> source >> dest;
    cout << BFS() << "\n";
    return 0;
}