/*

*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; 

const int MOD = 1e9+7;
const int MAXN = 1e5+5;
vector<int> graph[MAXN];
vector<int> topo;
bool visited[MAXN];
int n, m;

void DFS(int curr)
{
    if(visited[curr]) return;
    for(const auto& neighbor : graph[curr])
    {
        DFS(neighbor);
    }
    topo.push_back(curr);
    visited[curr] = true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i) DFS(i);
    reverse(topo.begin(), topo.end());
    vector<int> dp(n+5);
    dp[1] = 1;
    for(const auto& node : topo)
    {
        for(const auto& neighbor : graph[node])
        {
            (dp[neighbor] += dp[node]) %= MOD;
        }
    }   
    cout << dp[n] << "\n"; 
    return 0; 
}