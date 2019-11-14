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
int color[MAXN];
int n, m, can = true;
vector<int> topo;

void DFS(int curr, int par)
{
    color[curr] = 1;
    for(const auto& neighbor : graph[curr])
    {
        if(color[neighbor] == 1) 
        {
            can = false;
            return;
        }
        if(neighbor == par || color[neighbor] == 2) continue;
        DFS(neighbor, curr);
    }
    topo.push_back(curr);
    color[curr] = 2;
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
    for(int i = 1; i <= n; ++i) if(color[i] == 0) DFS(i, -1);
    if(!can) cout << "IMPOSSIBLE\n";
    else
    {
        reverse(topo.begin(), topo.end());
        for(int i = 0; i < topo.size(); ++i)
        {
            cout << topo[i];
            (i+1 == topo.size()) ? cout << "\n" : cout << " ";
        }
    }
    return 0; 
}