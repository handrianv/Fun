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
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, ans = 0;
    cin >> n;
    n /= 2;
    int maxsum = n*9;

    vector<int> dp(maxsum+5);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = maxsum; j > 0; --j)
        {
            for(int k = 1; k <= 9; ++k)
            {
                if(k > j) continue;
                dp[j] += dp[j-k];
            }
            if(i == n) ans += dp[j] * dp[j];
        }
    }
    cout << ans+1 << "\n";
    return 0; 
}       