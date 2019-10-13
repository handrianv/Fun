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

const int MAXLOG = 19;
const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int parent[MAXN][MAXLOG];
int n, q;

void DFS(int curr, int par)
{
    parent[curr][0] = par;
    for(int i = 1; i < MAXLOG; ++i)
    {
        parent[curr][i] = (parent[curr][i-1] == -1) ? -1 : parent[parent[curr][i-1]][i-1];
    }
    for(const auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        DFS(neighbor, curr);
    }
}

int Query(int node, int level)
{
    for(int i = 0; i < MAXLOG; ++i)
    {
        if(level & (1<<i))
        {
            node = parent[node][i];
            if(node == -1) return node;
        }
    }
    return node;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    DFS(1, -1);
    while(q--)
    {
        int x, k;
        cin >> x >> k;
        cout << Query(x, k) << "\n";
    }
    return 0; 
}           