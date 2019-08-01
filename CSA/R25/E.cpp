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

const int MAXN = 1005;
int n, m, dfsNum, ans = 1, root = MAXN*MAXN+2;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
vector<int> graph[MAXN*MAXN+5];
int board[MAXN+5][MAXN+5];
bool visited[MAXN*MAXN+5];
int start[MAXN*MAXN+5], low[MAXN*MAXN+5],sz[MAXN*MAXN+5];

bool Valid(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void DFS(int curr, int p)
{
    visited[curr] = true;
    start[curr] = low[curr] = ++dfsNum;
    ++sz[curr];
    int dc = 0;

    for(auto neighbor : graph[curr])
    {
        if(neighbor == p) continue;
        if(visited[neighbor]) low[curr] = min(low[curr], start[neighbor]);
        else
        {
            DFS(neighbor, curr);
            sz[curr] += sz[neighbor];
            low[curr] = min(low[curr], low[neighbor]);
            if(low[neighbor] >= start[curr] && p != -1)
            {
                dc += sz[neighbor];
            }
        }
    }
    if(p != -1) ans = max(ans, dc+1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    int numBlack = 0;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> board[i][j];

    // Build graph
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(!board[i][j])
            {
                int curr = j + (i*m);
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    graph[root].push_back(curr);
                    graph[curr].push_back(root);
                } 
                for(int k = 0; k < 2; ++k)
                {
                    int nxtR = i + dx[k];
                    int nxtC = j + dy[k];
                    if(Valid(nxtR, nxtC) && !board[nxtR][nxtC])
                    {
                        int nxt = nxtC + (nxtR * m);
                        graph[curr].push_back(nxt);
                        graph[nxt].push_back(curr);
                    }
                } 
            }
            else ++numBlack;
        }
    }
    DFS(root, -1);
    cout << (ans + numBlack) << "\n";
    return 0;
}   