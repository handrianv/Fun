/* 
    First compute the answer without regarding updates. It's standard tree dp.
    For every update, we can loop every updated node and update answer in O(1) / O(log(N)) using LCA.

    We split the given m operations into sqrt(M) blocks. Then:
    -. Before start of every block, run the DP. For all blocks this takes O(M sqrt(N)) time.
    -. Within each block, at most sqrt(N) nodes can be updated, and each query can be answered in roughly O(sqrt(N)).
       For all block this takes roughly O(M sqrt(N)) time
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

const int MAXN = 5e4+5, MAXLOG = 20;
const int MAGIC = 750;
vector<int> graph[MAXN];
int color[MAXN], depth[MAXN], subSz[MAXN][2];
ll dpSub[MAXN][2], dpAll[MAXN][2];
int par[MAXN][MAXLOG];
int n, m;

void DFS(int curr, int parr)
{
    par[curr][0] = parr;
    for(int i = 1; i < MAXLOG; ++i) par[curr][i] = par[par[curr][i-1]][i-1];
    for(const auto& neighbor : graph[curr])
    {
        if(neighbor == parr) continue;
        depth[neighbor] = depth[curr] + 1;
        DFS(neighbor, curr);
    }
}
 
int LCA(int a, int b)
{
    if(depth[a] > depth[b]) swap(a, b);
 
    int jump = 0;
    for(int i = depth[b]-depth[a]; i > 0; i/=2)
    {
        if(i&1) b = par[b][jump];
        ++jump;
    }
 
    if(a==b) return a;
 
    for(int i = MAXLOG-1; i >= 0; --i)
    {
        if(par[a][i] != par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}
 
int Dist(int a, int b)
{
    return depth[a] + depth[b] - 2*depth[LCA(a, b)];
}

void DPSub(int curr, int par)
{
    subSz[curr][color[curr]] = 1; subSz[curr][color[curr]^1] = 0;
    dpSub[curr][0] = dpSub[curr][1] = 0;
    for(auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        DPSub(neighbor, curr);

        for(int c = 0; c < 2; ++c)
        {
            dpSub[curr][c] += dpSub[neighbor][c] + subSz[neighbor][c];
            subSz[curr][c] += subSz[neighbor][c];
        }
    }
}

void DPAll(int curr, int par)
{
    for(auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        for(int c = 0; c < 2; ++c)
        {
            dpAll[neighbor][c] = dpAll[curr][c] + subSz[1][c] - 2*subSz[neighbor][c];
        }
        DPAll(neighbor, curr);
    }
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> color[i];
    }
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1, 1);

    int counter = 0;
    unordered_set<int> changed; changed.reserve(MAGIC+10);
    for(int i = 0; i < m; ++i)
    {
        if(counter == 0)
        {
            changed.clear();
            DPSub(1, -1);
            dpAll[1][0] = dpSub[1][0]; dpAll[1][1] = dpSub[1][1];
            DPAll(1, -1);
        }
        ++counter;
        if(counter == MAGIC) counter = 0;

        int type, v;
        cin >> type >> v;
        if(type == 1)
        {
            if(changed.count(v)) changed.erase(v); else changed.insert(v);
            color[v] ^= 1;
        }
        else
        {
            ll ans = dpAll[v][color[v]];
            for(auto& c : changed)
            {
                int d = Dist(v, c);
                if(color[c] == color[v]) ans += d;
                else ans -= d;
            }
            cout << ans << "\n";
        }
    }
    return 0; 
}