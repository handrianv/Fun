/* 
    Better way: Do Dijkstra on reverse graph too
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1e5+5;
ll dist[MAXN][2]; // 0: Not use coupon, 1: use
vector<pi> graph[MAXN];
int n, m;

void Dijkstra()
{
    memset(dist, -1, sizeof(dist));
    set<pair<pli, bool>> s; // {{cost, node}, use coupon}
    s.insert({{0, 1}, false});
    dist[1][false] = 0;

    while(!s.empty())
    {
        pair<pli, bool> curr = *(s.begin());
        s.erase(s.begin());
        ll currDist = curr.first.first, currCity = curr.first.second;
        bool use = curr.second;

        for(const auto& neighbor : graph[currCity])
        {
            ll nxtDist = currDist + neighbor.first;
            int nxtCity = neighbor.second;

            if(!use)
            {
                ll temp = currDist + neighbor.first / 2;
                if(dist[nxtCity][true] == -1 || temp < dist[nxtCity][true])
                {
                    s.erase({{dist[nxtCity][true], nxtCity}, true});
                    dist[nxtCity][true] = temp;
                    s.insert({{dist[nxtCity][true], nxtCity}, true});
                }
            }

            if(dist[nxtCity][use] == -1 || nxtDist < dist[nxtCity][use])
            {
                s.erase({{dist[nxtCity][use], nxtCity}, use});
                dist[nxtCity][use] = nxtDist;
                s.insert({{dist[nxtCity][use], nxtCity}, use});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m, q;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    Dijkstra();
    cout << dist[n][true] << "\n";
    return 0; 
}           