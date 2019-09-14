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
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

 
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, x;
    cin >> n >> x;
    vector<int> coins(n+5);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    vector<int> dp(x+5);
    dp[0] = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = coins[i]; j <= x; ++j)
        {
            dp[j] += dp[j-coins[i]];
            if(dp[j] >= MOD) dp[j] -= MOD;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}