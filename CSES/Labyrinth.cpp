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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1005;
int n, m;
char board[MAXN][MAXN];
int dRow[4] = {0, 0, 1, -1};
int dCols[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'D', 'U'};
int dist[MAXN][MAXN];
pi par[MAXN][MAXN];
char parDir[MAXN][MAXN];

bool Valid(int row, int cols)
{
    return (row >= 0 && row < n && cols >= 0 && cols < m && board[row][cols] != '#');
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    pi start, finish;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
    {
        cin >> board[i][j];
        if(board[i][j] == 'A') start = {i, j};
        else if(board[i][j] == 'B') finish = {i, j};
    } 

    memset(dist, -1, sizeof(dist));
    dist[start.first][start.second] = 0;
    queue<pi> que;
    que.push(start);
    while(!que.empty())
    {
        pi curr = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i)
        {
            int nxtRow = curr.first + dRow[i];
            int nxtCols = curr.second + dCols[i];
            if(Valid(nxtRow, nxtCols) && dist[nxtRow][nxtCols] == -1)
            {
                dist[nxtRow][nxtCols] = dist[curr.first][curr.second] + 1;
                que.push({nxtRow, nxtCols});
                par[nxtRow][nxtCols] = curr; 
                parDir[nxtRow][nxtCols] = dir[i];
            }
        }
    }
    if(dist[finish.first][finish.second] == -1) cout << "NO\n";
    else
    {
        string ans = "";
        while(finish != start)
        {
            ans += parDir[finish.first][finish.second];
            finish = par[finish.first][finish.second];
        }
        reverse(ans.begin(), ans.end());
        cout << "YES\n" << ans.size() << "\n" << ans << "\n";
    }
    
    return 0;
}   