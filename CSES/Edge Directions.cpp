/* 
    TODO: Better algo
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
vector<pi> edges;
int color[MAXN];
int n, m;

void DFS(int curr, int par)
{
    int seenPar = 0; // for multiple edges, we'll see par more than once
    color[curr] = 1;
    for(const auto& neighbor : graph[curr])
    {
        if(neighbor == par)
        {
            ++seenPar;
            if(seenPar > 1) edges.push_back({neighbor, curr});
            continue;
        } 
        if(color[neighbor] == 1) edges.push_back({neighbor, curr});
        else if(color[neighbor] == 0)
        {
            edges.push_back({curr, neighbor});
            DFS(neighbor, curr);
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
    for(int i = 1; i <= n; ++i) if(color[i] == 0) DFS(i, i);
    for(const auto& edge : edges) cout << edge.first << " " << edge.second << "\n";
    return 0; 
}       