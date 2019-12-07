/*
    Example of problem where bottom-up dp is much faster than top down
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

const int MAXN = 505;
int a, b;
int dp[MAXN][MAXN];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    for(int i = 1; i <= a; ++i)
    {
        for(int j = 1; j <= b; ++j)
        {
            if(i == j) continue;
            int ans = 1e9+7;

            // Horizontal
            for(int k = 1; k < i; ++k) ans = min(ans, dp[k][j] + dp[i-k][j] + 1);
            // Vertical
            for(int k = 1; k < j; ++k) ans = min(ans, dp[i][k] + dp[i][j-k] + 1);
            dp[i][j] = ans;
        }
    }
    cout << dp[a][b] << "\n";
    return 0; 
}