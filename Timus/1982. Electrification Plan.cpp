/*
    Observation:
    Connect all power stations to imaginary node x with cost 0. Build MST.
    
    Informal proof:
    -. Connectivity: In a tree there is a path between every pair of node (a, b).
                     So in the MST, every node must be connected to x. But the only connection to x is through the power stations. So every node must be connected to x through one of these power stations.
                     Now remove every edge to x, every node is still connected to one power station (Bonus: why only to one?).
    -. Minimum: Every edge to x has cost 0, so removing it doesn't increase the total weight, and since it's an MST, it's minimum.
                    
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 105;
int n, k;
vector<pair<int, pi>> edgeList;
int par[MAXN];

int FindSet(int x)
{
    return ((x == par[x]) ? x : par[x] = FindSet(par[x]));
}

bool IsSameSet(int x, int y)
{
    return (FindSet(x) == FindSet(y));
}

void Union(int x, int y)
{
    int a = FindSet(x), b = FindSet(y);
    par[a] = b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> k;
    for(int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        edgeList.push_back({0, {0, x}});
    }
    for(int i = 1; i <= n; ++i)
    {
        par[i] = i;
        for(int j = 1; j <= n; ++j)
        {
            int cost;
            cin >> cost;
            edgeList.push_back({cost, {i, j}});
        }
    }

    sort(edgeList.begin(), edgeList.end());
    int ans = 0;
    for(auto& edge : edgeList)
    {
        if(!IsSameSet(edge.second.first, edge.second.second))
        {
            ans += edge.first;
            Union(edge.second.first, edge.second.second);
        }
    }
    cout << ans << "\n";
    return 0; 
}