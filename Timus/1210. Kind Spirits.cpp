/* 
    Shortest path in DAG.
*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <bitset>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 9005;
vector<pi> graph[MAXN]; // {cost, idx}
int dp[MAXN];
bool visited[MAXN];
int n, nodeNum = 0, mn = 2e9; // lowest node idx in last level

int DFS(const int& curr)
{
    if(visited[curr]) return dp[curr];
    visited[curr] = true;
    if(curr >= mn && curr <= nodeNum) dp[curr] = 0; // Any node at last level

    for(auto& neighbor : graph[curr])
    {
        dp[curr] = min(dp[curr], DFS(neighbor.second) + neighbor.first);
    }

    return dp[curr];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    vector<int> prevLevel(1);

    for(int level = 1; level <= n; ++level)
    {
        int k;
        cin >> k;
        vector<int> temp(k);
        for(int j = 0; j < k; ++j)
        {
            temp[j] = ++nodeNum;
            if(level == n && j == 0) mn = nodeNum;
            int prev;
            cin >> prev;
            while(prev > 0)
            {
                int cost;
                cin >> cost;
                graph[prevLevel[prev-1]].push_back({cost, nodeNum});
                //cout << "push " << prevLevel[prev-1] << " to " << nodeNum << "\n";
                cin >> prev;
            }
        }
        prevLevel = temp;

        if(level < n)
        {
            char trash;
            cin >> trash;
        }
    }

    for(int i = 0; i <= nodeNum; ++i) dp[i] = 2e9;
    DFS(0);
    cout << dp[0] << "\n";
    return 0;
}
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/