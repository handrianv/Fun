/* 
    We can do normal TSP DP and prune all states that:
    -. Visits 1 as the last city but mask is not 1
    -. Vistis n as the last city but mask is not (1<<n) -1
    Which will reduce the usual time complexity by factor of 4
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
 
const int MAXN = 20;
const int MOD = 1e9+7;
vector<int> graph[MAXN];
int dp[1<<MAXN][MAXN];
int n, m;
 
int DP(int mask, int last)
{
    if(last == 0) return (mask == 1);
    if(dp[mask][last] != -1) return dp[mask][last];

    dp[mask][last] = 0;
    int nxt = mask ^ (1<<last);
    for(auto& neighbor : graph[last])
    {
        if(neighbor == last || !(mask&(1<<neighbor))) continue;
        dp[mask][last] += DP(nxt, neighbor);
        dp[mask][last] %= MOD;
    }
    return dp[mask][last];
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    memset(dp, -1, sizeof(dp)); 
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[b].push_back(a);    
    }
    cout << DP((1<<n)-1, n-1) << "\n";
    return 0; 
}