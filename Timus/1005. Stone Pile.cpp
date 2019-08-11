/* 
    Knapsack with capacity (sum of weights / 2)
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
    vector<int> w(n+5);
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> w[i];
        sum += w[i];
    } 

    int limit = sum/2;
    vector<int> dp(limit+5);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = limit; j >= 0; --j)
        {
            if(w[i] <= j)
                dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
        }
    }
    cout << (sum-2*dp[limit]) << "\n";
    return 0;
}   