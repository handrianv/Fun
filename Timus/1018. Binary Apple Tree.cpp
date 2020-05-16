/* 
    Clarif: might not be clear from the statement, but the subset of nodes preserved should still be connected
    The problem is asking for maximum weight subtree rooted at 1 with k edges

    State
    dp[n][k] = answer for subtree of node n if we need to take k edges

    Transition
    We can try taking x edges from the left child and n-x edges from the right child for every 0 <= x <= k
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 105;
int n, q;
vector<int> graph[MAXN];
int val[MAXN][MAXN];
int dp[MAXN][MAXN];
int sz[MAXN];

void DFS(int curr, int par)
{
    sz[curr] = 1;
    for(auto& child : graph[curr])
    {
        if(child != par)
        {
            DFS(child, curr);
            sz[curr] += sz[child];
        }
    }
}

int DP(int curr, int par, int need)
{
    if(need <= 0) return 0;
    if(dp[curr][need] != -1) return dp[curr][need];

    int left = -1, right = -1;
    for(auto& child : graph[curr]) if(child != par) {left = child; break;}
    for(auto& child : graph[curr]) if(child != par && child != left) {right = child; break;}

    if(right == -1) return dp[curr][need] = DP(left, curr, need-1) + val[left][curr];

    dp[curr][need] = 0;
    for(int take = 0; take <= need; ++take)
    {
        if(take-1 > sz[left]-1 || need-take-1 > sz[right]-1) continue;
        int leftAns = (take > 0) ? DP(left, curr, take-1) + val[left][curr] : 0;
        int rightAns = (need-take > 0) ? DP(right, curr, need-take-1) + val[right][curr] : 0;
        dp[curr][need] = max(dp[curr][need], leftAns + rightAns);
    }
    return dp[curr][need];
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q; 
    for(int i = 0; i < n-1; ++i)
    {
        int a, b, v;
        cin >> a >> b >> v;
        graph[a].push_back(b); graph[b].push_back(a);
        val[a][b] = val[b][a] = v;
    }
    memset(dp, -1, sizeof(dp));
    DFS(1, 1);
    cout << DP(1, 1, q) << "\n";
    return 0;  
}