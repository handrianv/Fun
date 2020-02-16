/* 

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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1e5+5, MOD = 1e9+7;
vector<pi> graph[MAXN]; // {cost, edge}
ll dist[MAXN];
int ansCnt[MAXN], ansMin[MAXN], ansMax[MAXN];
int n, m; 

void Dijkstra()
{
    memset(dist, -1, sizeof(dist));
    set<pli> s; // {dist, node}
    s.insert({0, 1});
    dist[1] = 0; ansCnt[1] = 1;

    while(!s.empty())
    {
        auto curr = *s.begin();
        s.erase(s.begin());
        ll currDist = curr.first; int currNode = curr.second;
        if(currNode == n) return;

        for(auto& neighbor : graph[currNode])
        {
            int nWeight = neighbor.first, nNode = neighbor.second;
            ll nxtDist = currDist + nWeight;

            if(dist[nNode] == -1 || dist[nNode] >= nxtDist)
            {
                if(dist[nNode] == -1 || dist[nNode] > nxtDist)
                {
                    ansCnt[nNode] = 0;
                    ansMin[nNode] = 1e9;
                    ansMax[nNode] = -1e9;
                }
                dist[nNode] = nxtDist;
                (ansCnt[nNode] += ansCnt[currNode]) %= MOD;
                ansMin[nNode] = min(ansMin[nNode], ansMin[currNode] + 1);
                ansMax[nNode] = max(ansMax[nNode], ansMax[currNode] + 1);
                
                s.erase({dist[nNode], nNode});
                s.insert({nxtDist, nNode});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    Dijkstra();
    cout << dist[n] << " " << ansCnt[n] << " " << ansMin[n] << " " << ansMax[n] << "\n";
    return 0; 
}
