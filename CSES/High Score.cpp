/* 
    Find shortest path and negative cycle with Bellman-Ford.
    If node n is reachable from any negative cycle, answer -1. We can do DFS from n on reverse graph to determine reachability.
*/

#include <stdio.h>
#include <bits/stdc++.h>
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
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const ll INF = 1e15;
const int MAXN = 2505;
int n, m;

// DFS
vector<int> rGraph[MAXN];
bool can[MAXN];
vector<int> dest;

// Bellman-Ford
vector<pair<int, pi>> edgeList;
ll dist[MAXN];

void DFS(int curr, int par)
{
    can[curr] = true;
    for(const auto& neighbor : rGraph[curr])
    {
        if(neighbor != par && !can[neighbor]) DFS(neighbor, curr);
    }
}

ll BellmanFord()
{
    for(int i = 2; i <= n; ++i) dist[i] = INF;
    for(int i = 1; i <= n; ++i)
    {
        for(const auto& edge : edgeList)
        {
            if(dist[edge.second.first] == INF) continue;
            ll temp = dist[edge.second.first] + edge.first;
            if(temp < dist[edge.second.second])
            {
                dist[edge.second.second] = temp;
                if(i == n) dest.push_back(edge.second.second);
            }
        }
    }
    return -dist[n];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back({-c, {a, b}});
        rGraph[b].push_back(a);
    }
    DFS(n, -1);
    ll ans = BellmanFord();
    for(const auto& node : dest)
    {
        if(can[node])
        {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0; 
}           