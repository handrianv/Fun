/*
    Solve the problem backwards.
    Create the graph but exclude edge that will be cut. Now the state of the graph corresponds to the state after all q cut have been executed.
    Start from the last cut, now cutting an edge becomes connecting nodes with an edge. After merging the last cut, the state corresponds to the state after q-1 cut have been executed.
    Continue until all q cuts have been merged.
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

const int MAXN = 100005;
vector<int> graph[MAXN];
int par[MAXN];
int n, m, numCC;

void Init()
{
    numCC = n;
    for(int i = 1; i <= n; ++i) par[i] = i;
}

int FindSet(int x)
{
    return ((par[x] == x) ? x : par[x] = FindSet(par[x]));
}

void Union(int x, int y)
{
    int a = FindSet(x), b = FindSet(y);
    if(a != b)
    {
        --numCC;
        par[a] = b;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    vector<pi> edges(m+5);
    for(int i = 1; i <= m; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    int q;
    cin >> q;
    vector<char> isCut(MAXN);
    vector<int> cuts(q);
    for(int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;
        isCut[x] = true;
        cuts[i] = x;
    }

    Init();
    for(int i = 1; i <= m; ++i)
    {
        if(!isCut[i])
        {
            Union(edges[i].first, edges[i].second);
        }
    }

    vector<int> ans(q);
    for(int i = q-1; i >= 0; --i)
    {
        ans[i] = numCC;
        Union(edges[cuts[i]].first, edges[cuts[i]].second);
    }

    for(int i = 0; i < q; ++i)
    {
        cout << ans[i];
        (i+1 == q) ? cout << "\n" : cout << " ";
    }
    return 0;
}
 
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/