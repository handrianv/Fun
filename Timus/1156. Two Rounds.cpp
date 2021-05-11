/*
    https://acm.timus.ru/problem.aspx?space=1&num=1156

    We can treat this as a graph problem. For each forbidden pair of problem, add an undirected edge, then the first requirement for the answer to
    exist is that the graph should be two-colorable (bipartite) and this should hold for all connected components. For the remaining explanation,
    we'll use the color red and blue.

    Now we want to check if we can split the problems into two sets of size N. So for each connected component, one color should be in the first set
    and the other color in the other set. Notice that the choice of color is independent between components i.e. if for component 1 we choose the red
    nodes to be in set 1, for component 2 we can also choose red to be in set 1.

    So if we represent each connected component as pair of {count of red nodes, count of blue nodes}, then we get a subset sum problem with a
    minor variation; we want subset of sum N and each item must be used (we must choose one of red/blue for each item).
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
#include <random>
#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define EPS 1e-9
#define CeilDiv(a, b) ((a + b - 1) / b)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 102;
vector<int> graph[MAXN];
int color[MAXN];
vector<int> components[MAXN][2];
int numCC = 0;
bool can = true;

void DFS(int curr, int c)
{
    color[curr] = c;
    components[numCC][c].push_back(curr);
    
    for(auto& neighbor : graph[curr])
    {
        if(color[neighbor] == -1)
        {
            DFS(neighbor, c^1);
        }
        else if(color[neighbor] == color[curr])
        {
            can = false;
            return;
        }
    }
}

// dp[i][j]: can we make sum j if we use up to the i'th CC
// Value of dp is the color we should take from this CC
vector<vector<int>> DP(const vector<pi>& knap, int n)
{
    vector<vector<int>> dp(knap.size(), vector<int>(n + 2, -1));
    dp[0][knap[0].first] = 0; dp[0][knap[0].second] = 1;

    for (int i = 1; i < (int)knap.size(); ++i)
    {
        for (int sum = 0; sum <= n; ++sum)
        {
            if(knap[i].first <= sum && dp[i-1][sum-knap[i].first] != -1)
            {
                dp[i][sum] = 0;
            }
            else if(knap[i].second <= sum && dp[i-1][sum-knap[i].second] != -1)
            {
                dp[i][sum] = 1;
            }
        }
    }
    return dp;
}


void Solve(const int& tc = 1)
{
    memset(color, -1, sizeof(color));
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<pi> knap;
    for(int i = 1; i <= 2*n; ++i)
    {
        if(color[i] == -1)
        {
            DFS(i, 0);
            knap.push_back({components[numCC][0].size(), components[numCC][1].size()});
            ++numCC;
        }
        if(!can)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    vector<vector<int>> dp = DP(knap, n);
    if(dp[knap.size()-1][n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // Backtrack
    vector<int> ans1, ans2;
    int idx = knap.size()-1, sum = n;
    auto Insert = [&](int c, vector<int>& ans) 
    {
        for (auto &v : components[numCC - 1][c])
        {
            ans.push_back(v);
        }
    };

    while (idx >= 0)
    {
        Insert(dp[idx][sum], ans1);
        Insert(dp[idx][sum] ^ 1, ans2);
        sum -= ((dp[idx][sum]) ? knap[idx].second : knap[idx].first);
        --idx;
        --numCC;
    }

    assert((int)ans1.size() == n);
    assert((int)ans2.size() == n);
    auto Print = [&](const vector<int>& ans)
    {
        for(int i = 0; i < n; ++i)
        {
            cout << ans[i] << " \n"[i+1==n];
        }
    };
    Print(ans1);
    Print(ans2);
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    for(int i = 1; i <= tc; ++i)
    {
        Solve(i);
    }
    return 0;
}

/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/