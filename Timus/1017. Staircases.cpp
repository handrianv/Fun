/* 
    State
    dp[n][h] = how many ways if we have n bricks and the maximum height for last step is h

    Transition
    dp[n][h] = dp[n][h-1] + dp[n-k][k-1] for every k <= n

    Don't forget to subtract the answer by 1, because staircase with only 1 step of height n is not valid.
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<vector<ll>> dp(n+5, vector<ll>(n+5));
    dp[0][0] = 1;

    for(int numBricks = 1; numBricks <= n; ++numBricks)
    {
        for(int lastH = 1; lastH <= numBricks; ++lastH)
        {
            dp[numBricks][lastH] = dp[numBricks][lastH-1] + dp[numBricks-lastH][min(numBricks-lastH, lastH-1)];
        }
    }

    cout << (dp[n][n]-1) << "\n";
    return 0;  
}