/* 
    First, let's count the number of valid sequence of some length. Let ways[n] be the number of valid sequence of length n, then:
    -. ways[n] = ways[n-1] + ways[n-2]

    Now, for an index i, if the i'th bit (from the left) is turned on, we know that the resulting sequence must be >= (ways[i-1] + 1)'th permutation and <= (ways[i])'th permutation.
    For example, ways[3] = 5 and ways[4] = 8. Then if the 4th bit is turned on, the resulting sequence must be >= 6th permutation (1000) and <= 8th permutation (1010).

    Now we want to find the k'th permutation. Then for an index i:
    -. If k >= (ways[i-1] + 1) and k <= (ways[i]), then we know the i'th bit must be turned on.
       After we turn it on, then for the remaining (i-1) bit we need to look for the (k - ways[i-1])'th permutation.

    -. Else the i'th bit must be turned off, and we need to look for the k'th permutation in the remaining (i-1) bit.
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;

    vector<ll> dp(n+5);
    dp[0] = 1, dp[1] = 2;
    for(int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    if(k > dp[n])
    {
        cout << "-1\n";
        return 0;
    }
  

    string ans = "";
    for(int i = n; i > 0; --i)
    {
        if(k > dp[i-1])
        {
            ans += "1";
            k -= (dp[i-1]);
        }
        else
        {
            ans += "0";
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
*/