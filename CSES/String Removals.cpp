/* 
    Question can be rephrased as "count number of distinct subsequence in the string"

    State:
    dp[i][ch] -> number of distinct subsequence of length i ending with character ch

    Transition:
    -. (ch != str[i]) then we can't create any new subsequence ending with ch, so dp[i][ch] = dp[i-1][ch]
    -. Else we can append ch to all dp[i-1][k] for every alphabet k, and it will end with ch (and all of them will still be distinct)
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
    string str;
    cin >> str;
    int n = str.size();
    vector<int> dp(30);
    for(int i = 1; i <= n; ++i)
    {
        int ch  = str[i-1] - 'a'; 
        int temp = 1; // Add to empty string
        for(int k = 0; k < 26; ++k)
        {
            (temp += dp[k]) %= MOD;
        }
        dp[ch] = temp;
    }
    int ans = 0;
    for(int i = 0; i < 26; ++i) (ans += dp[i]) %= MOD;
    cout << ans << "\n";
    return 0; 
}