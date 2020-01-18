/* 
    This solution is the same dp as editorial, but another dp is possible.

    State:
    dp[i][j] = number of distinct palindrome in range (i, j)
    Transition:
    
    Loop every character c, and take L = next occurence of c after i, R = prev occurence of c before j
    Then dp[i][j] = 2 + dp[L+1][R-1] if L != R, else it's 1
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
const int MAXN = 1005;
int dp[MAXN][MAXN][30];
int n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    cin >> str;
    int n = str.size();

    for(int len = 1; len <= n; ++len)
    {
        for(int left = 1; left+len-1 <= n; ++left)
        {
            int right = left+len-1;
            for(int c = 0; c < 26; ++c)
            {
                dp[left][right][c] = (dp[left+1][right][c] + dp[left][right-1][c]) % MOD;
                (dp[left][right][c] -= dp[left+1][right-1][c]) %= MOD;
                if(dp[left][right][c] < 0) dp[left][right][c] += MOD;
            }

            if(str[left-1] == str[right-1])
            {
                int curr = str[left-1] - 'a';
                dp[left][right][curr] = 1 + (left < right);
                for(int c = 0; c < 26; ++c)
                {
                    (dp[left][right][curr] += dp[left+1][right-1][c]) %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int c = 0; c < 26; ++c) (ans += dp[1][n][c]) %= MOD;
    cout << ans << "\n";
    return 0; 
}