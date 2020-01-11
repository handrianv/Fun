/* 
  State
  dp[i][1/2]: How many valid string of length i ending in (1/2)

  Transition:
  Inclusion-exclusion. Let's try to append 1 to all dp[i-1][1] & dp[i-1][2].
  Since 1 can appear at most A times, we need to exclude those of length (i-1) ending with A 1.
  Because we fixed the last A character to be 1, the number of string with length (i-1) ending with A 1 is dp[i-A-1][2].

  So final transition is dp[i][1] = (dp[i-1][1] + dp[i-1][2] - dp[i-A-1][2]). Similary for those ending with 2. 
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

const int MOD = 1e9+7;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> dp(n+5, vector<int>(2)); // {Length, end with 1 / 2}
    dp[0][0] = dp[0][1] = dp[1][1] = dp[1][0] = 1;
    for(int i = 2; i <= n; ++i)
    {
      dp[i][0] = dp[i][1] = ((dp[i-1][0] + dp[i-1][1]) % MOD);
      if(i >= a+1)
      {
        (dp[i][0] -= dp[i-a-1][1]) %= MOD;
        if(dp[i][0] < 0) dp[i][0] += MOD;
      }

      if(i >= b+1)
      {
        (dp[i][1] -= dp[i-b-1][0]) %= MOD;
        if(dp[i][1] < 0) dp[i][1] += MOD;
      }
    }
    cout << ((dp[n][0] + dp[n][1]) % MOD) << "\n";
    return 0; 
}