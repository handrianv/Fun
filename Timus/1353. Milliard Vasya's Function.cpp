/* 
    Knapsack DP
    
    State:
    dp[i][s] -> How many number with i digits have sum s
    
    Transition:
    dp[i][s] = dp[i-1][s] + dp[i-1][s-x] from x = 1 to 9
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
    int s;
    cin >> s;
    vector<int> dp(100);
    dp[0] = 1;
    for(int i = 1; i <= 9; ++i)
    {
        for(int sum = s; sum >= 0; --sum)
        {
            for(int k = 1; k <= 9; ++k)
            {
                if(sum-k < 0) continue;
                dp[sum] += dp[sum-k];
            }
        }   
    }
    if(s == 1) ++dp[s];
    cout << dp[s] << "\n";
    return 0; 
}       