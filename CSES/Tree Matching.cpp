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

const int MAXN = 2e5+5;
int dp[MAXN][2]; // {Node, is it matched with one of child}
int n;
vector<int> graph[MAXN];

void DFS(int curr, int par)
{
    int bestMatch = 0;
    for(const auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        DFS(neighbor, curr);
        dp[curr][0] += max(dp[neighbor][0], dp[neighbor][1]);
        bestMatch = max(bestMatch, 1 + dp[neighbor][0] - max(dp[neighbor][0], dp[neighbor][1]));
    }
    dp[curr][1] = dp[curr][0] + bestMatch;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(1, 1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}   