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
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1e5+5;
vector<int> graph[MAXN];
int color[MAXN];
int n, m, valid = true;

void DFS(int curr)
{
    for(const auto& neighbor : graph[curr])
    {
        if(color[neighbor] == -1)
        {
            color[neighbor] = color[curr] ^ 1;
            DFS(neighbor);
        }
        else if(color[neighbor] == color[curr])
        {
            valid = false;
            return;
        }
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(color, -1, sizeof(color));
    for(int i = 1; i <= n; ++i)
    {
        if(color[i] == -1)
        {
            color[i] = 0;
            DFS(i);
        }
    }
    if(!valid) cout << "IMPOSSIBLE\n";
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            cout << color[i]+1;
            (i == n) ? cout << "\n" : cout << " ";
        }
    }
    return 0;
}