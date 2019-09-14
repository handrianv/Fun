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
int par[MAXN], dist[MAXN];
int n, m;

void BFS()
{
    queue<int> que;
    que.push(1);
    for(int i = 2; i <= n; ++i) dist[i] = MOD;

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();

        for(const auto& neighbor : graph[curr])
        {
            if(dist[curr]+1 < dist[neighbor])
            {
                dist[neighbor] = dist[curr]+1;
                que.push(neighbor);
                par[neighbor] = curr;
            }
        }
    }
}

void PrintPath()
{
    vector<int> ans;
    int curr = n;
    while(par[curr] != 0)
    {
        ans.push_back(curr);
        curr = par[curr];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        (i+1 == ans.size()) ? cout << "\n" : cout << " ";
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

    BFS();
    if(par[n] == 0) cout << "IMPOSSIBLE\n";
    else
    {
        cout << dist[n]+1 << "\n";
        PrintPath();
    }
    return 0;
}