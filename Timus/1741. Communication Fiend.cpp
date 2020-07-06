/*
    Shortest path on DAG with state [node][Licensed/Pirated]
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
 
#define LSOne(S) (S & (-S))
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Edge {
    int e, cost, type; // {0: pirate, 1: licensed, 2: cracked}
    Edge() {}
    Edge(int x, int y, int z) : e(x), cost(y), type(z) {}
};

const int MAXN = 1e4+5; const ll INVALID = 1e18;
vector<Edge> graph[MAXN];
ll dist[MAXN][2]; // {node, pirate / not}
int n, m;

ll DP(int curr, bool isLicensed)
{
    if(dist[curr][isLicensed] != -1) return dist[curr][isLicensed];
    if(curr == n) return dist[curr][isLicensed] = 0;
    dist[curr][isLicensed] = INVALID;

    for(auto& edge : graph[curr])
    {
        if(!isLicensed && edge.type == 1) continue; // Can't use licensed on pirate
        bool nxtLicensed = (edge.type == 2) ? isLicensed : edge.type;
        dist[curr][isLicensed] = min(dist[curr][isLicensed], edge.cost + DP(edge.e, nxtLicensed));
    }

    return dist[curr][isLicensed];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; string type;
        cin >> a >> b >> c >> type;
        int t = ((type[0] == 'P') ? 0 : (type[0] == 'C') ? 2 : 1);
        graph[a].push_back(Edge(b, c, t));
    }

    memset(dist, -1, sizeof(dist));
    ll ans = DP(1, 1);
    (ans == INVALID) ? cout << "Offline\n" : cout << "Online\n" << ans << "\n";
    return 0;
}
