/*
    The important observation is:
    -. The order of operation doesn't matter. For any set of flips, the only thing that determines the final value of a cell is how many flips "touched" it, regardless of the order of flips
    -. Applying flip to a same cell (same as in, we choose the same center for the 3x3 cell) twice is useless; it's the same as not flipping it. So each cell should be flipped either once or not at all.
    With these observations, we can just bruteforce all combinations of cells to flip using bitmask
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

const int INF = 1e9;

int Try(vector<vector<char>> board, const vector<vector<char>>& mov, int mask)
{
    int ans = 0;
    for(int b = 0; b < 16; ++b)
    {
        if(mask & (1<<b))
        {
            ++ans;
            int r = b/4, c = b%4;

            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; ++j)
                {
                    int rr = r-1+i, cc = c-1+j;
                    if(min(rr, cc) >= 0 && max(rr, cc) < 4 && mov[i][j] == '1')
                    {
                        (board[rr][cc] == 'W') ? board[rr][cc] = 'B' : board[rr][cc] = 'W';
                    }
                }
            }
        }
    }

    int cntW = 0, cntB = 0;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            (board[i][j] == 'W') ? ++cntW : ++cntB;
        }
    }
    if(cntW > 0 && cntB > 0) ans = INF;
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<vector<char>> board(4, vector<char>(4));
    for(int i = 0;  i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<char>> mov(3, vector<char>(3));
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cin >> mov[i][j];
        }
    }

    int ans = INF;
    for(int mask = 0; mask < (1<<16); ++mask)
    {
        ans = min(ans, Try(board, mov, mask));
    }
    (ans == INF) ? cout << "Impossible\n" : cout << ans << "\n";
    return 0;
}
 
/*
 
*/  