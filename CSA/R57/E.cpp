/* 
    Hint: Solve row and column independently
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

const ll MOD = 1e9+7LL;
vector<vector<ll>> getDP(ll k, ll n)
{
    vector<vector<ll>> dp(k+5, vector<ll>(n+5));
    dp[0][0] = 1;
    for(int i = 1; i <= k; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            ll pickOne = (dp[i-1][n-j+1] * (n-j+1)) % MOD;
            ll pickZero = 0;
            if(n-j-1 >= 0 ) pickZero = (dp[i-1][n-j-1] * (j+1)) % MOD;
            dp[i][j] = (pickOne + pickZero) % MOD;
        }
    }
    return dp;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m, k, s;
        cin >> n >> m >> k >> s;
        vector<vector<ll>> dpRow = getDP(k, n);
        vector<vector<ll>> dpCols = getDP(k, m);

        ll ans = 0;
        for(int oddRow = 0; oddRow <= n; ++oddRow)
        {
            for(int oddCols = 0; oddCols <= m; ++oddCols)
            {
                ll totalOnes = oddRow * (m-oddCols) + oddCols * (n-oddRow);
                if(totalOnes == s)
                {
                    ll temp = (dpRow[k][oddRow] * dpCols[k][oddCols]) % MOD;
                    (ans += temp) %= MOD;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0; 
}