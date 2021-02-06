/*

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
#include <random>
#include <chrono>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
   
const int MAXN = 1e5+5;
const int LEFT = 0, DOWN = 1, UP = 2;
int board[2][MAXN];
ll dp[2][MAXN][3];
bool done[2][MAXN][3];
int m;

ll DP(int row, int cols, int dir, int player)
{
    if(done[row][cols][dir]) return dp[row][cols][dir];
    if(row == 1 && cols == m-1) return board[row][cols];
    if(row == 0 && cols == m-1) return board[row][cols] + board[row+1][cols];

    dp[row][cols][dir] = board[row][cols];
    if(dir == UP || dir == DOWN)
    {
        dp[row][cols][dir] += DP(row, cols+1, LEFT, player^1);
    }
    else
    {
        ll horizontal = DP(row, cols+1, LEFT, player^1);
        ll vertical = (row == 0) ? DP(row+1, cols, UP, player^1) : DP(row-1, cols, DOWN, player^1);
        ll t = 0;
        if(player == 0)
        {
            t += max(horizontal, vertical);
        }
        else
        {
            t += min(horizontal, vertical);
        }
        dp[row][cols][dir] += t;
    }    
    done[row][cols][dir] = true;
    return dp[row][cols][dir];
}


int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    cin >> m;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
    cout << DP(0, 0, LEFT, 1) << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
cout << setprecision for doubles!! Costed me half a day of life!!
*/  