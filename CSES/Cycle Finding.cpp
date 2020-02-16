/* 

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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 2505;
vector<pair<pi, int>> edges;
ll dist[MAXN];
int par[MAXN];
int n, m;

void Backtrack(int x)
{
    // N iteration guarantees we're now in the cycle
    for(int i = 0; i < n; ++i)
    {
        x = par[x];
    }

    int target = x;
    vector<int> ans;
    do {
        ans.push_back(x);
        x = par[x];
    } while(x != target);
    ans.push_back(x);
    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    for(auto& node : ans) cout << node << " ";
    exit(0);
}

void BellmanFord()
{
    for(int i = 1; i <= n; ++i)
    {
        for(auto& edge : edges)
        {
            int a = edge.first.first, b = edge.first.second, c = edge.second;
            if(dist[a] + c < dist[b])
            {
                par[b] = a;
                dist[b] = dist[a] + c;

                if(i == n)
                {
                    Backtrack(b);
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    edges = vector<pair<pi, int>>(m);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {{a, b}, c};
    }
    BellmanFord();
    cout << "NO\n";
    return 0; 
}