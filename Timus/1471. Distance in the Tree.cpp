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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 5e4+5;
const int LOGN = 17;
vector<pi> graph[MAXN];
int parent[MAXN][LOGN+5]; // {dist, parent}
int depth[MAXN], dist[MAXN];
int n;

void DFS(int curr, int par)
{
    parent[curr][0] = par;

    for(int i = 1; i <= LOGN; ++i)
    {
        parent[curr][i] = parent[parent[curr][i-1]][i-1];
    }
    for(auto& child : graph[curr])
    {
        if(child.second == par) continue;
        depth[child.second] = depth[curr] + 1;
        dist[child.second] = dist[curr] + child.first;
        DFS(child.second, curr);
    }
}

int LCA(int x, int y)
{
    if(depth[x] > depth[y]) swap(x, y);

    int jump = 0;
    for(int i = depth[y]-depth[x]; i > 0; i/=2)
    {
        if(i&1)
        {
            y = parent[y][jump];
        }
        ++jump;
    }

    if(x==y) return x;

    for(int i = LOGN; i >= 0; --i)
    {
        if(parent[x][i] != parent[y][i])
        {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[x][0];
}

int Dist(int x, int y)
{
    return (dist[x] + dist[y] - 2*dist[LCA(x, y)]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    DFS(0, 0);

    int m;
    cin >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        cout << Dist(a, b) << "\n";
    }
    return 0;
}
 
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)

6
0 1 100
1 2 200
0 3 300
3 4 400
3 5 500
*/