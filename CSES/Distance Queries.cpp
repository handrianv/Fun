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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
const int MAXLOG = 19;
const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int par[MAXN][MAXLOG];
int depth[MAXN];
int n, q;
 
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
 
int Dist(int a, int b)
{
    return depth[a] + depth[b] - 2*depth[LCA(a, b)];
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(1, 1);
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << Dist(a, b) << "\n";
    }
    return 0; 
}          