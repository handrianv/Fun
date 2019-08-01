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

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

const int MAXN = 1005;
int board[MAXN][MAXN];
int dRow[4] = {0, 0, 1, -1};
int dCols[4] = {1, -1, 0, 0};
int sz[MAXN*MAXN];
int n, m, currComponent = 2, ans = 0;

bool valid(int row, int cols)
{
    return (row >= 0 && row < n && cols >= 0 && cols < m);
}

void DFS(int row, int cols)
{
    board[row][cols] = currComponent;
    ++sz[currComponent];
    ans = max(ans, sz[currComponent]);

    for(int i = 0; i < 4; ++i)
    {
        int nxtRow = row + dRow[i];
        int nxtCols = cols + dCols[i];
        if(valid(nxtRow, nxtCols) && board[nxtRow][nxtCols] == 1)
        {
            DFS(nxtRow, nxtCols);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> board[i][j];
    for(int i = 0; i < n; ++i) 
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] != 1) continue;
            DFS(i, j);
            ++currComponent;
        }
    }


    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] != 0) continue;
            int temp = 1;
            set<int> seen;

            for(int k = 0; k < 4; ++k)
            {
                int nxtRow = i + dRow[k];
                int nxtCols = j + dCols[k];
                if(valid(nxtRow, nxtCols) && seen.find(board[nxtRow][nxtCols]) == seen.end())
                {
                    temp += sz[board[nxtRow][nxtCols]];
                    seen.insert(board[nxtRow][nxtCols]);
                }
            }

            ans = max(ans, temp);
        }
    }

    cout << ans << "\n";
    return 0;
}