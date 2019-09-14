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
int n, m;
vector<int> graph[MAXN];
bool visited[MAXN];

void DFS(int curr)
{
    visited[curr] = true;
    for(const auto& neighbor : graph[curr])
    {
        if(!visited[neighbor]) DFS(neighbor);
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

    vector<int> ans;
    for(int i = 1; i <= n; ++i)
    {
        if(!visited[i])
        {
            DFS(i);
            ans.push_back(i);
        }
    }

    cout << (ans.size()-1) << "\n";
    for(int i = 0; i+1 < ans.size(); ++i)
    {
        cout << ans[i] << " " << ans[i+1] << "\n";
    }
    return 0;
}