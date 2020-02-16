/* 
    TODO: SIMPLIFY IMPLEMENTATION.

    The graph is shaped such that a component consists of a simple cycle and several path leading to the cycle.
    Imagine the non-cycle edge has its direction reversed, then every non-cycle edge is a tree edge rooted at a cycle node.

    Four type of path is possible:
    1.  Cycle-cycle
        It's possible only if both node belongs in same component

    2.  Non-cycle - Non-cycle
        Since it's directed tree, we can use simpler form of LCA where we only need to check that after several jump both nodes are the same.

    3.  Non-cycle - cycle
        Go to the root of non-cycle node, then it reduces to case 1

    4.  Cycle - non-cycle
        Impossible.
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
 
const int MAXN = 2e5+5, MAXLOG = 18;
int nxt[MAXN], color[MAXN], par[MAXN], indeg[MAXN];
// cycle
int cycleId[MAXN], cycleLen[MAXN], cycleNum[MAXN];
// lca
int depth[MAXN], nxt2[MAXN][MAXLOG+2];
// 
int root[MAXN];
int n, q, cid, cnum;

void UpdateCycleData(int curr)
{
    root[curr] = curr;
    cycleId[curr] = cid;
    cycleNum[curr] = ++cnum;
}

void Backtrack(int curr, int target)
{
    ++cid; int len = 1;
    while(curr != target)
    {
        UpdateCycleData(curr);
        curr = par[curr];
        ++len;
    }
    UpdateCycleData(curr);
    cycleLen[cid] = len;
}

void DFS(int curr)
{
    color[curr] = 1;
    if(color[nxt[curr]] == 0)
    {
        par[nxt[curr]] = curr;
        DFS(nxt[curr]);
    } 
    else if(color[nxt[curr]] == 1)
    {
        Backtrack(curr, nxt[curr]);
    }
    color[curr] = 2;
}

void DFS2(int curr)
{
    if(color[nxt[curr]] == 0)
    {
        DFS2(nxt[curr]);
    }
    root[curr] = root[nxt[curr]];
    depth[curr] = depth[nxt[curr]] + 1;
    color[curr] = 2;    

    nxt2[curr][0] = nxt[curr];
    for(int i = 1; i <= MAXLOG; ++i)
    {
        nxt2[curr][i] = nxt2[nxt2[curr][i-1]][i-1];
    }
}

bool Query(int a, int b)
{
    if(depth[a] < depth[b]) return false;

    int jump = 0;
    for(int i = depth[a]-depth[b]; i > 0; i/=2)
    {
        if(i&1) a = nxt2[a][jump];
        ++jump;
    }

    return (a == b);
}

int BetweenCycle(int a, int b)
{
    int ans = 0;
    int ca = cycleNum[a], cb = cycleNum[b];
    if(ca >= cb) ans = ca-cb;
    else ans = cycleLen[cycleId[a]] - (cb-ca);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        nxt[i] = x;
        ++indeg[nxt[i]];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(color[i] == 0) DFS(i);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(cycleId[i] == 0) color[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(indeg[i] == 0) DFS2(i);
    }

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int ans = -1;

        // Between cycle, only possible if within the same cycle
        if(cycleId[a] != 0 && cycleId[b] != 0 && cycleId[a] == cycleId[b])
        {
            //cout << "Case 1\n";
            ans = BetweenCycle(a, b);
        }
        // Between non-cycle, only possible if rooted in same cycle node
        else if(cycleId[a] == 0 && cycleId[b] == 0 && (root[a] == root[b]) && Query(a, b))
        {
            //cout << "Case 2\n";
            ans = depth[a] - depth[b];
        }
        // From non-cycle to cycle. Root of non-cycle must be within same cycle
        else if(cycleId[a] == 0 && cycleId[b] != 0)
        {
            //cout << "Case 3\n";
            if(cycleId[root[a]] == cycleId[b])
            {
                ans = depth[a] + BetweenCycle(root[a], b);
            }
        }

        cout << ans << "\n";
    }
    return 0; 
}
