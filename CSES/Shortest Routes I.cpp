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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1e5+5;
vector<pli> graph[MAXN];
ll dist[MAXN];
int n, m;

void Dijkstra()
{
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    set<pli> s;
    s.insert({0, 1});

    while(!s.empty())
    {
        pli curr = *(s.begin());
        s.erase(s.begin());
        int currCity = curr.second; ll currDist = curr.first;

        for(const auto neighbor : graph[currCity])
        {
            int nxtCity = neighbor.second;
            ll nxtDist = currDist + neighbor.first;
            if(dist[nxtCity] == -1 || nxtDist < dist[nxtCity])
            {
                s.erase({dist[nxtCity], nxtCity});
                dist[nxtCity] = nxtDist;
                s.insert({dist[nxtCity], nxtCity});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    Dijkstra();
    for(int i = 1; i <= n; ++i)
    {
        cout << dist[i];
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0; 
}           