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

const int MAXN = 1e5+5;
vector<int> graph[MAXN];
int dp[MAXN], nxt[MAXN];
int n, m;

int DFS(int curr)
{
    if(dp[curr] != -1) return dp[curr];
    dp[curr] = -1e9+7;
    for(const auto& neighbor : graph[curr])
    {
        int temp = DFS(neighbor) + 1;
        if(temp > dp[curr])
        {
            dp[curr] = temp;
            nxt[curr] = neighbor;
        }
    }
    return dp[curr];
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
    memset(dp, -1, sizeof(dp));
    dp[n] = 1;
    DFS(1);
    if(dp[1] < 2) cout << "IMPOSSIBLE\n";
    else
    {
        cout << dp[1] << "\n";
        int curr = 1;
        while(nxt[curr] != 0)
        {
            cout << curr << " ";
            curr = nxt[curr];
        }
        cout << curr << "\n";
    }
    
    return 0; 
}