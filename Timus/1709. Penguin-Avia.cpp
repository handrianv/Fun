/*
    The important observation is that the solution must be a tree, because a tree is a connected component with minimum number of edges.

    Solution 1
    The problem maps quite naturally to MST. We create a complete graph where each edge has cost "a" if it doesn't exist in the original graph, and 0 otherwise.
    Then we run MST and whenever we encounter cycle edge that is part of the original graph, it means we need to delete it for cost "d".

    Solution 2
    For a single connected component, we need to transform it into a tree by deleting all cycle edges (or subtract total number of edges with (n-1), where n is node size of connected component).
    For multiple connected component, we need to transform each one into a tree. Now we have a forest, and we can easily transform it into a tree by adding edge between roots.
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 105;
vector<int> graph[MAXN];
int color[MAXN];
char ansMat[MAXN][MAXN];
int n, cycleEdge = 0;
ll a, d;

void DFS(int curr, int par)
{
    color[curr] = 1;
    for(auto& child : graph[curr])
    {
        if(child == par) continue;
        if(color[child] == 0)
        {
            DFS(child, curr);
        }
        else if(color[child] == 1)
        {
            ansMat[curr][child] = ansMat[child][curr] = 'd';
            ++cycleEdge;
        }
    }
    color[curr] = 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> d >> a;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) ansMat[i][j] = '0';

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            char has;
            cin >> has;
            if(has == '1' && i <= j)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    ll ans = 0;
    vector<int> roots;
    for(int i = 0; i < n; ++i)
    {
        if(color[i] == 0)
        {
            roots.push_back(i);
            cycleEdge = 0;
            DFS(i, i);
            ans += (d * cycleEdge);
        }
    }

    ans += (a * (roots.size()-1));
    for(int i = 1; i < (int)roots.size(); ++i)
    {
        ansMat[roots[i]][roots[i-1]] = ansMat[roots[i-1]][roots[i]] = 'a';
    }

    cout << ans << "\n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << ansMat[i][j];
            if(j+1 == n) cout << "\n";
        }
    }
    return 0;
}


// MST based solution
// const int MAXN = 105;
// int adjMat[MAXN][MAXN];
// int par[MAXN];
// int n, d, a;

// void Init()
// {
//     for(int i = 0; i < n; ++i) par[i] = i;
// }

// int FindSet(int x)
// {
//     return ((par[x] == x) ? x : par[x] = FindSet(par[x]));
// }

// bool Union(int x, int y)
// {
//     int aa = FindSet(x), bb = FindSet(y);
//     if(aa != bb)
//     {
//         par[aa] = bb;
//         return true;
//     }
//     return false;
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
//     cin >> n >> d >> a;
//     vector<pair<int, pi>> edges; edges.reserve(n*n+5);
//     for(int i = 0; i < n; ++i)
//     {
//         for(int j = 0; j < n; ++j)
//         {
//             char has;
//             cin >> has;
//             adjMat[i][j] = (has == '1');
//             if(i > j) continue;
//             if(has == '1')
//             {
//                 edges.push_back({0, {i, j}});
//             }
//             else
//             {
//                 edges.push_back({a, {i, j}});
//             }
//         }
//     }

//     sort(edges.begin(), edges.end());
//     Init();

//     ll ans = 0;
//     vector<vector<char>> ansMat(n, vector<char>(n));
//     for(auto& edge : edges)
//     {
//         int cost = edge.first;
//         int x = edge.second.first, y = edge.second.second;
//         char ch;
//         if(Union(x, y))
//         {
//             if(adjMat[x][y])
//             {
//                 ch = '0';
//             }
//             else
//             {
//                 ans += cost;
//                 ch = 'a';
//             }
//         }
//         else
//         {
//             if(adjMat[x][y])
//             {
//                 ans += d;
//                 ch = 'd';
//             }
//             else
//             {
//                 ch = '0';
//             }
//         }
//         ansMat[x][y] = ansMat[y][x] = ch;
//     }
    
//     cout << ans << "\n";
//     for(int i = 0; i < n; ++i)
//     {
//         for(int j = 0; j < n; ++j)
//         {
//             cout << ansMat[i][j];
//             if(j+1 == n) cout << "\n";
//         }
//     }
//     return 0;
// }
