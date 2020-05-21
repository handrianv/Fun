/* 
    State
    dp[i][j][dir] = Minimum cost to get to position (i, j) if we come from direction dir
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

const int INF = 1e9+5;
const int MAXN = 505;
int n, m;
int board[MAXN][MAXN];
int dp[MAXN][MAXN][3]; // {row, cols, UP/LEFT/RIGHT}

void Backtrack(int row, int cols, int dir)
{
    if(row != 0)
    {
        int prevRow = row - (dir == 0);
        int prevCols = cols;
        if(dir != 0) prevCols += ((dir == 1) ? -1 : 1);

        for(int prevDir = 0; prevDir < 3; ++prevDir)
        {
            if((dir == 1 && prevDir == 2) || (dir == 2 && prevDir == 1)) continue;
            if(dp[prevRow][prevCols][prevDir] + board[row][cols] == dp[row][cols][dir])
            {
                Backtrack(prevRow, prevCols, prevDir);
                break;
            }
        }
    }

    cout << (cols+1);
    (row == n-1) ? cout << "\n" : cout << " ";
}

void Print()
{
    vector<int> temp(3); // {val, cols, dir}
    temp[0] = INF;
    for(int j = 0; j < m; ++j)
    {
        for(int dir = 0; dir < 3; ++dir)
        {
            if(dp[n-1][j][dir] < temp[0])
            {
                temp = {dp[n-1][j][dir], j, dir};
            }
        }
    }

    Backtrack(n-1, temp[1], temp[2]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    // Base case
    for(int j = 0; j < m; ++j) 
    {
        dp[0][j][0] = board[0][j];
        dp[0][j][1] = dp[0][j][2] = INF;
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            // Get here from UP
            dp[i][j][0] = *min_element(dp[i-1][j], dp[i-1][j] + 3) + board[i][j];
            // Get here from LEFT
            (j == 0) ? dp[i][j][1] = INF : dp[i][j][1] = min(dp[i][j-1][0], dp[i][j-1][1]) + board[i][j];
        }

        for(int j = m-1; j >= 0; --j)
        {
            // Get here from RIGHT
            (j == m-1) ? dp[i][j][2] = INF : dp[i][j][2] = min(dp[i][j+1][0], dp[i][j+1][2]) + board[i][j];
        }
    }

    Print();
    return 0;  
}