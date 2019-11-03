/* 
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
 
const ll INF = 1e17;
const int MAXN = 1e5+5;
int n, m, k;
vector<pi> graph[MAXN];
ll dist[MAXN][12];
 
void Dijkstra()
{
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= k; ++j) dist[i][j] = INF; 
    set<pair<ll, pi>> s; // {dist, {city, k}}
    s.insert({0, {1, 1}});
    dist[1][1] = 0;
 
    while(!s.empty())
    {
        auto curr = *(s.begin());
        s.erase(s.begin());
        ll currDist = curr.first;
        int currCity = curr.second.first, currK = curr.second.second;
 
        for(const auto& neighbor : graph[currCity])
        {
            ll nxtDist = currDist + neighbor.first;
            int nxtCity = neighbor.second;
 
            // Try to relax the k-th distance
            // If we relaxed the k-th distance, then the (k+1)th distance becomes k-th distance, (k+2) becomes (k+1) and so on...
            for(int j = currK; j <= k; ++j)
            {
                if(nxtDist < dist[nxtCity][j])
                {
                    s.erase({dist[nxtCity][j], {nxtCity, j}});
                    swap(nxtDist, dist[nxtCity][j]);
                    s.insert({dist[nxtCity][j], {nxtCity, j}});
                }
            }
        }
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    Dijkstra();
    for(int i = 1; i <= k; ++i)
    {
        cout << dist[n][i];
        (i == k) ? cout << "\n" : cout << " ";
    }
    return 0; 
}           