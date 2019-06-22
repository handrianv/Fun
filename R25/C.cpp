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
typedef pair<ll, int> pli;

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

const int MAXN = 1000;
int n, m, h, w, sr, sc, fr, fc;
int board[MAXN+5][MAXN+5];
bool visited[MAXN+5][MAXN+5];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
bool can = false;

bool valid(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void mark(int r, int c, pi origin)
{
    board[r][c] = 1;
    visited[r][c] = true;
    for(int i = 0; i < 4; ++i)
    {
        int nxtr = r + dr[i];
        int nxtc = c + dc[i];
        if(valid(nxtr, nxtc) && !visited[nxtr][nxtc] && nxtr <= origin.first && nxtc <= origin.second && origin.first-nxtr+1 <= h && origin.second-nxtc+1 <= w)
        {
            mark(nxtr, nxtc, origin);
        }
    }
}

int bfs()
{
    if(sr == fr && sc == fc) return 0;
    queue<pi> que;
    que.push({sr, sc});
    visited[sr][sc] = true;
    int mov = 0;
    while(!que.empty())
    {
        ++mov;
        int sz = que.size();
        for(int i = 0; i < sz; ++i)
        {
            pi curr = que.front();
            que.pop();
            int r = curr.first, c = curr.second;

            for(int j = 0; j < 4; ++j)
            {
                int nxtr = r + dr[j];
                int nxtc = c + dc[j];
                if(valid(nxtr, nxtc) && nxtr+h-1 < n && nxtc+w-1 < m && !visited[nxtr][nxtc] && board[nxtr][nxtc] == 0)
                {
                    if(nxtr == fr && nxtc == fc) return mov;
                    que.push({nxtr, nxtc});
                    visited[nxtr][nxtc] = true;
                }
            }
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<pi> invalids;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if(board[i][j])
            {
                invalids.push_back({i, j});
            }
        }
    }
    cin >> h >> w >> sr >> sc >> fr >> fc;
    --sr; --sc; --fr; --fc;
    for(auto i : invalids)
    {
        if(!visited[i.first][i.second]) mark(i.first, i.second, i);
    }
    memset(visited, false, sizeof(visited));
    cout << bfs() << "\n";
    return 0;
}   

