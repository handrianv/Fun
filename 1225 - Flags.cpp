/*
    DP.
    State: 
        dp[n][k] -> length n and ending color k (white or red)
    Transition: 
        If ending color is white, then previous color can be red (+dp[n-1][red]) or previous color blue, then previous previous color must be red (+dp[n-2][red]).
        So dp[n][white] = dp[n-1][red] + dp[n-2][red]
        For color ending in red is similar
    
    Improvements:
    -. Number of ways ending in white / red is symmetrical, so you can throw away second dimension, compute it for one color only and multiply the end result by 2.
    -. No need to actually store entire dp array, just need the last two. So you can throw away first dimension as well and replace it with 2 variables.
    Now it's a fibonacci problem
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    ll prev = 0, curr = 1;
    for(int i = 2; i <= n; ++i)
    {
        ll temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    cout << (curr*2) << "\n";
    return 0;
}   