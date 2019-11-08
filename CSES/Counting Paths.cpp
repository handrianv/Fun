/* 
    Slower way
    Give every path an id and for every node store the set of id that goes through this node.
    Then for every node we just merge the set of its children. Use small-to-large technique.
    For every path with endpoint (A, B), the path id will appear twice in LCA(A, B). In this case-
    -be careful to increase the answer for LCA(A, B) by only one, and remove the path id from the set so that it doesn't propagate up the tree.

    Faster way
    We do something similar to the slower way, but we just store the count of path that goes through this node.
    For every path (A, B) we increase ans[A] & ans[B] and decrease ans[LCA(A, B)] (to avoid double counting) and ans[parent[LCA(A, B)]] (so it doesn't propagate up)
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// ---------- Faster way ----------
const int MAXN = 2e5+5;

const int MAXLOG = 19;
vector<int> graph[MAXN];
int par[MAXN][MAXLOG];
int depth[MAXN], ans[MAXN];
int n, m;

void DFS(int curr, int parr)
{
    par[curr][0] = parr;
    for(int i = 1; i < MAXLOG; ++i) par[curr][i] = par[par[curr][i-1]][i-1];
    for(const auto& neighbor : graph[curr])
    {
        if(neighbor == parr) continue;
        depth[neighbor] = depth[curr] + 1;
        DFS(neighbor, curr);
    }
}

int LCA(int a, int b)
{
    if(depth[a] > depth[b]) swap(a, b);

    int jump = 0;
    for(int i = depth[b]-depth[a]; i > 0; i/=2)
    {
        if(i&1) b = par[b][jump];
        ++jump;
    }

    if(a==b) return a;

    for(int i = MAXLOG-1; i >= 0; --i)
    {
        if(par[a][i] != par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

void DFS2(int curr, int par)
{
    for(const auto& child : graph[curr])
    {
        if(child == par) continue;
        DFS2(child, curr);
        ans[curr] += ans[child];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(1, 0);
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        ++ans[a]; ++ans[b];
        int x = LCA(a, b);
        --ans[x]; --ans[par[x][0]];
    }
    DFS2(1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cout << ans[i];
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0;
}

// ---------- Slower way ----------
// const int MAXN = 2e5+5;
// vector<int> graph[MAXN];
// set<int> s[MAXN];
// int ans[MAXN];
// int n, m;

// void DFS(int curr, int par)
// {
//     int temp = 0;
//     for(const auto& child : graph[curr])
//     {
//         if(child == par) continue;
//         DFS(child, curr);
//         if(s[curr].size() < s[child].size()) swap(s[curr], s[child]);
//         for(const auto& i : s[child])
//         {
//             // Will only happen in LCA(A, B)
//             if(s[curr].count(i))
//             {
//                 s[curr].erase(i);
//                 ++temp;
//             } 
//             else
//             {
//                 s[curr].insert(i);
//             }
//         }
//     }
//     ans[curr] += (s[curr].size() + temp);
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
//     cin >> n >> m;
//     for(int i = 0; i < n-1; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     for(int i = 0; i < m; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         s[a].insert(i);
//         if(a != b) 
//         {
//             s[b].insert(i);
//         }
//         else
//         {
//             s[a].erase(i);
//             ++ans[a];
//         }  
//     }
//     DFS(1, 1);
//     for(int i = 1; i <= n; ++i)
//     {
//         cout << ans[i];
//         (i == n) ? cout << "\n" : cout << " ";
//     }
//     return 0; 
// }           