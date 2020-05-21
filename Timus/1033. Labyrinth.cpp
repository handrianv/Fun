/* 
    Append walls around the input, then do flood fill.
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
typedef pair<bool, int> pbi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const char WALL = '#';
const int MAXN = 35;
char board[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dRow[4] = {0, 0, 1, -1};
int dCols[4] = {1, -1, 0, 0};
int n;

bool Valid(int row, int cols)
{
    return (row >= 0 && row <= n+1 && cols >= 0 && cols <= n+1);
}

int BFS()
{
    queue<pi> que;
    que.push({1, 1}); que.push({n, n});
    visited[1][1] = visited[n][n] = true;
    int ans = 0;

    while(!que.empty())
    {
        pi curr = que.front();
        que.pop();
        int currRow = curr.first, currCols = curr.second;

        for(int i = 0; i < 4; ++i)
        {
            int nxtRow = currRow + dRow[i];
            int nxtCols = currCols + dCols[i];

            if(Valid(nxtRow, nxtCols))
            {
                if(board[nxtRow][nxtCols] == WALL) ++ans;
                else if(!visited[nxtRow][nxtCols])
                {
                    visited[nxtRow][nxtCols] = true;
                    que.push({nxtRow, nxtCols});
                }
            }
        }
    }
    //cout << "Returning " << ans << "\n";
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i <= n+1; i += (n+1))
    {
        for(int j = 0; j <= n+1; ++j)
        {
            board[i][j] = board[j][i] = WALL;
        }
    }

    int ans = BFS() * 9 - 36;
    cout << ans << "\n";
    return 0;  
}