/* 
    TODO: Use better algo
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
ll n;
ll dp[55][2];
ll suff[55];
 
ll DP(int curr, bool tight)
{
    if(dp[curr][tight] > 0) return dp[curr][tight];
    if(curr < 0) return 0;
    bool currBit = (n & (1LL << curr)) > 0;
 
    if(!tight)
    {
        dp[curr][tight] += (2 * DP(curr-1, false) + (1LL << curr));
    }
    else
    {
        dp[curr][tight] += DP(curr-1, currBit == 0);
        if(currBit == 1)
        {
            dp[curr][tight] += (DP(curr-1, true) + ((curr-1 < 0) ? 1 : suff[curr-1]+1));
        }
    }
    return dp[curr][tight];
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    suff[0] = (n & 1);
    for(int i = 1; i < 50; ++i)
    {
        suff[i] = suff[i-1];
        if(n & (1LL << i)) suff[i] += (1LL << i);
    }
    cout << DP(50, true) << "\n";
    return 0;
}