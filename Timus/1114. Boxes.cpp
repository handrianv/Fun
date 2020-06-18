/* 
    The key observation is we can count the answer for each ball independently; That is, pretend there is only one type of ball.
    After that, for every ways of arranging red ball, we can mix it with any way of arranging blue balls, so we can just multiply the result.

    Solution #1
    We use DP. State: dp[i][j] = how many ways if we have i boxes and the last box contains j balls.

    Transition: We can put zero until j balls in the last box. So dp[i][j] = Sum(dp[i-1][k]) for every k in [0, j]

    Solution #2
    Stars and bars. We want to put a fixed number j balls in i boxes. This is well-known and the answer is C(i+j-1, j). See https://en.wikipedia.org/wiki/Stars_and_bars_(combinatorics)
    But in this problem we don't have to use all the balls. Suppose we want to count ways for red balls. Max number of red balls is a.
    So we want Sum(C(i+j-1, j)) for every j in [0, a]. This is the hockeystick identity and it's equal to C(i+a, a). 
    One simple way to prove it is to use a very similar way of using star and bars for fixed number of j balls, but pretend there is one more box (or bar). This last box holds the balls the we didn't use.

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
#include <bitset>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ull comb[40][25];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    for(int i = 0; i <= 35; ++i)
    {
        comb[i][0] = 1;
        for(int j = 1; j <= i && j <= 20; ++j)
        {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    int n, a, b;
    cin >> n >> a >> b;
    cout << (comb[n+a][a] * comb[n+b][b]) << "\n";
    //if(a > b) swap(a, b);

    // vector<vector<ull>> dp(n+5, vector<ull>(b+5));
    // fill(dp[0].begin(), dp[0].end(), 1);

    // for(int i = 1; i <= n; ++i)
    // {
    //     for(int j = 0; j <= b; ++j)
    //     {
    //         for(int last = 0; last <= j; ++last)
    //         {
    //             dp[i][j] += dp[i-1][j-last];
    //         }
    //     }
    // }

    // cout << (dp[n][a] * dp[n][b]) << "\n";
    return 0;
}
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/