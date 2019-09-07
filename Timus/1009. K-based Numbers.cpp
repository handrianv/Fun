/* 
    DP
    State: dp[n] = answer for length n
    Transition: -. last digit doesn't end with zero then we have (k-1) choice for the last digit so dp[i-1] * (k-1)
                -. last digit ends with zero then the we have (k-1) choice for the previous digit, so dp[i-2] * (k-1)

    Optimization: To compute current state we need only last two state, so we can replace dp array with two variables.
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
 

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;
    ll prev = 1, curr = k-1;
    for(int i = 2; i <= n; ++i)
    {
        ll temp = (k-1) * (prev + curr);
        prev = curr;
        curr = temp;
    }
    cout << curr << "\n";
    return 0;
}