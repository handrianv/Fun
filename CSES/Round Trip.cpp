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

const int MAXN = 1e5+5;
vector<int> graph[MAXN];
int n, m;
int color[MAXN], par[MAXN];

void PrintPath(int stop, int start)
{
    vector<int> path;
    while(stop != start)
    {
        path.push_back(stop);
        stop = par[stop];
    }
    path.push_back(stop);
    cout << path.size()+1 << "\n";
    for(const auto& p : path)
    {
        cout << p << " ";
    }
    cout << path[0] << "\n";
    exit(0);
}

void DFS(int curr)
{
    color[curr] = 1; 
    for(const auto& neighbor : graph[curr])
    {
        if(neighbor == par[curr]) continue;
        if(color[neighbor] == 1) PrintPath(curr, neighbor);
        else if(color[neighbor] == 0)
        {
            par[neighbor] = curr;
            DFS(neighbor);
        }
    }
    color[curr] = 2;
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
    for(int i = 1; i <= n; ++i) if(color[i] == 0) DFS(i);
    cout << "IMPOSSIBLE\n";
    return 0; 
}       