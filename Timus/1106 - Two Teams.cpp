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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 105;
int n;
vector<int> graph[MAXN];
vector<int> ans;
int color[MAXN];

void DFS(int curr, int par)
{
    if(color[curr] == 1) ans.push_back(curr);
    for(auto neighbor : graph[curr])
    {
        if(neighbor != par && color[neighbor] == 0)
        {
            color[neighbor] = (color[curr] == 1) ? 2 : 1;
            DFS(neighbor, curr);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int j = -1;
        cin >> j;
        while(j != 0)
        {
            graph[i].push_back(j);
            graph[j].push_back(i);
            cin >> j;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!color[i])
        {
            color[i] = 1;
            DFS(i, i);
        }
    }
    
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        (i == ans.size()-1) ? cout << "\n" : cout << " ";
    }
    return 0;
}   