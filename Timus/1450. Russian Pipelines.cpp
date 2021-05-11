/*
    Classic max path in DAG.
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
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 505, NOT_FOUND = -100;
vector<pi> graph[MAXN];
int dp[MAXN];
int n, m, s, f;

int DP(int curr)
{
    if(curr == f) return dp[curr] = 0; 
    if(dp[curr] != -1) return dp[curr];

    dp[curr] = NOT_FOUND;
    for(auto& v : graph[curr])
    {
        if(DP(v.second) != NOT_FOUND)
        {
            dp[curr] = max(dp[curr], v.first + dp[v.second]);
        }
    }
    return dp[curr];
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    cin >> s >> f;
    memset(dp, -1, sizeof(dp));
    int ans = DP(s);
    (ans == NOT_FOUND) ? cout << "No solution\n" : cout << ans << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/  