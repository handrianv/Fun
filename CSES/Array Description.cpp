/*
    State
    dp[n][m] == how many ways to have array with length n and last number m

    Transition
    Let the current number x = arr[n]
    Case 1 (x > 0): then dp[n][x] =  dp[n-1][x] + dp[n-1][x-1] + dp[n-1][x+1]. Every other entry except dp[n][x] is zero.
    Case 2 (x == 0): same as case 1, but in this case x can be anywhere from 1-max number
*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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

const int MOD = 1e9+7;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m;
    cin >> n >> m;
    vector<int> vec(n+5);
    for(int i = 0; i < n; ++i) cin >> vec[i];

    vector<int> dp(m+5);
    if(vec[0] > 0) dp[vec[0]] = 1;
    else dp = vector<int>(m+5, 1);

    for(int i = 1; i < n; ++i)
    {
        vector<int> newDp(m+5);
        for(int j = 1; j <= m; ++j)
        {
            if(vec[i] == 0 || vec[i] == j)
            {
                if(j-1 > 0) (newDp[j] += dp[j-1]) %= MOD;
                if(j+1 <= m) (newDp[j] += dp[j+1]) %= MOD;
                (newDp[j] += dp[j]) %= MOD;
            }
        }
        swap(dp, newDp);
    }
    
    int ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        (ans += dp[i]) %= MOD;
    }
    cout << ans << "\n";
    return 0; 
}