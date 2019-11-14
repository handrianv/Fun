/* 
    For each edge (A, B) if we want these two vertices to be the endpoints of the cycle
    then we need to find shortest path from A to B that doesn't use (A, B).
    
    So for every edge we can run a slightly modified BFS that doesn't consider this edge.
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
 
const int MAXN = 2505;
vector<int> graph[MAXN];
vector<pi> edgeList;
int dist[MAXN];
int n, m;
 
int BFS(int source, int dest)
{
    memset(dist, -1, sizeof(dist));
    dist[source] = 0;
    queue<int> que;
    que.push(source);
 
    while(!que.empty())
    {
        int curr = que.front();
        que.pop();
        for(const auto& neighbor : graph[curr])
        {
            if(source == curr && dest == neighbor) continue;
            if(dist[neighbor] == -1)
            {
                dist[neighbor] = dist[curr] + 1;
                if(neighbor == dest) return dist[neighbor] + 1;
                que.push(neighbor);
            }
        }
    }
    return 1e9+7;
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
        graph[b].push_back(a);
        edgeList.push_back({a, b});
    }
    int ans = 1e9+7;
    for(const auto& edge : edgeList)
    {
        ans = min(ans, BFS(edge.first, edge.second));
    }
    if(ans == 1e9+7) ans = -1;
    cout << ans << "\n";
    return 0; 
}