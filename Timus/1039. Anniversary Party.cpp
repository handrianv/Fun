/* 
    We want maximum independent set. Since it's a tree, we can do DP similar to the classic maximum matching in a tree

    State
    dp[i][b] = answer for subtree rooted at i, and b is a boolean denoting whether node i is chosen as part of the set

    Transition
    dp[i][true] = value[i] + sum of dp[neighbor][false]. (We take this node, so we can't take any neighboring node).
    dp[i][false] = Sum of max(dp[neighbor][true], dp[neighbor][false]) (We didn't take this node, so for neighbor we can either take or not take).
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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef pair<bool, int> pbi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 6005;
int val[MAXN];
int dp[MAXN][2]; // {Answer for subtree, chosen / not chosen}
vector<int> graph[MAXN];
int n;

void DFS(int curr, int par)
{
    dp[curr][1] = val[curr];
    for(auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        DFS(neighbor, curr);
        dp[curr][0] += max(dp[neighbor][0], dp[neighbor][1]);
        dp[curr][1] += dp[neighbor][0];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    DFS(0, 0);
    cout << max(dp[0][0], dp[0][1]) << "\n";
    return 0;  
}