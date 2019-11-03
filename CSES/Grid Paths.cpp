/* 
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
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MOD = 1e9+7;
const int MAXN = 1005;
char board[MAXN][MAXN];
int n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cin >> board[i][j];

    vector<ll> dp(n+5);
    if(board[1][1] == '.') ++dp[1];
    for(int i = 1; i <= n; ++i)
    {
        vector<ll> newDp(n+5);
        for(int j = 1; j <= n; ++j)
        {
            if(board[i][j] == '*') continue;
            newDp[j] += newDp[j-1];
            if(newDp[j] >= MOD) newDp[j] -= MOD;
            newDp[j] += dp[j];
            if(newDp[j] >= MOD) newDp[j] -= MOD;
        }
        dp = newDp;
    }
    cout << dp[n] << "\n";
    return 0; 
}           