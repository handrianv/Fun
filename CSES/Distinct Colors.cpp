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

const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int ans[MAXN];
set<int> colors[MAXN];
int n;

void DFS(int curr, int par)
{
    for(auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        DFS(neighbor, curr);
        if(colors[curr].size() < colors[neighbor].size()) swap(colors[curr], colors[neighbor]);
        for(auto& color : colors[neighbor]) colors[curr].insert(color);
    }
    ans[curr] = colors[curr].size();
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int color;
        cin >> color;
        colors[i].insert(color);
    }
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(1, 1);
    for(int i = 1; i <= n; ++i)
    {
        cout << ans[i];
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0; 
}