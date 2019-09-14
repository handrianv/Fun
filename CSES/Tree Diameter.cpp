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

const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int n;

// {Node, Dist}
pi BFS(int source)
{
    vector<int> dist(n+5, MOD);
    queue<int> que;
    que.push(source);
    dist[source] = 0;
    pi res(source, 0);

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();

        for(const auto& neighbor : graph[curr])
        {
            if(dist[curr] + 1 < dist[neighbor])
            {
                dist[neighbor] = dist[curr] + 1;
                que.push(neighbor);

                if(res.second < dist[neighbor])
                {
                    res = {neighbor, dist[neighbor]};
                }
            }
        }
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << BFS(BFS(1).first).second << "\n";
    return 0;
}