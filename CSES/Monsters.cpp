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
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1005;
char board[MAXN][MAXN];
int n, m;
vector<pi> mSources;
pi aSource;
int distM[MAXN][MAXN], distA[MAXN][MAXN];
int par[MAXN][MAXN];
int dRow[4] = {0, 0, 1, -1};
int dCols[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'D', 'U'};

bool Valid(int row, int cols)
{
    return (row >= 0 && row < n && cols >= 0 && cols < m && board[row][cols] != '#');
}

bool IsBorder(int row, int cols)
{
    return ((row == 0 || row == n-1) || (cols == 0 || cols == m-1));
}

void Print(int row, int cols)
{
    string path = "";
    while(par[row][cols] != -1)
    {
        path += dir[par[row][cols]];
        int nxtRow = row + (-1 * dRow[par[row][cols]]);
        int nxtCols = cols + (-1 * dCols[par[row][cols]]);
        row = nxtRow;
        cols = nxtCols;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n" << path.size() << "\n" << path << "\n";
    exit(0);
}

void BFSM()
{
    queue<pi> que;
    for(const auto& monster : mSources)
    {
        que.push(monster);
        distM[monster.first][monster.second] = 0;
    }
    while(!que.empty())
    {
        pi curr = que.front();
        que.pop();
        int currRow = curr.first, currCols = curr.second;
        int nxtDist = distM[currRow][currCols] + 1;

        for(int i = 0; i < 4; ++i)
        {
            int nxtRow = currRow + dRow[i];
            int nxtCols = currCols + dCols[i];
            if(Valid(nxtRow, nxtCols) && nxtDist < distM[nxtRow][nxtCols])
            {
                distM[nxtRow][nxtCols] = nxtDist;
                que.push({nxtRow, nxtCols});
            }
        }
    }
}

void BFSA()
{
    memset(par, -1, sizeof(par));
    queue<pi> que;
    que.push(aSource);
    distA[aSource.first][aSource.second] = 0;

    while(!que.empty())
    {
        pi curr = que.front();
        que.pop();
        int currRow = curr.first, currCols = curr.second;
        int nxtDist = distA[currRow][currCols] + 1;
        if(IsBorder(currRow, currCols)) Print(currRow, currCols);
        //cout << "now " << currRow << " " << currCols << endl;

        for(int i = 0; i < 4; ++i)
        {
            int nxtRow = currRow + dRow[i];
            int nxtCols = currCols + dCols[i];
            int temp = min(distA[nxtRow][nxtCols], distM[nxtRow][nxtCols]);

            if(Valid(nxtRow, nxtCols) && nxtDist < temp)
            {
                distA[nxtRow][nxtCols] = nxtDist;
                par[nxtRow][nxtCols] = i;
                que.push({nxtRow, nxtCols});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if(board[i][j] == 'M') mSources.push_back({i, j});
            else if(board[i][j] == 'A') aSource = {i, j};

            distM[i][j] = distA[i][j] = 1e9+7;
        }
    }

    BFSM();
    BFSA();
    cout << "NO\n";
    return 0; 
}           