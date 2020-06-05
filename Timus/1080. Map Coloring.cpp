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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 105;
vector<int> graph[MAXN];
int color[MAXN];
int n, can = true; 

void DFS(int curr, int par)
{
    for(auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        if(color[neighbor] == color[curr])
        {
            cout << "-1\n";
            exit(0);
        }
        if(color[neighbor] == -1)
        {
            color[neighbor] = color[curr] ^ 1;
            DFS(neighbor, curr);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int j;
        cin >> j;
        while(j > 0)
        {
            graph[i].push_back(j);
            graph[j].push_back(i);
            cin >> j;
        }
    }

    memset(color, -1, sizeof(color));
    color[1] = 0;
    DFS(1, 1);

    for(int i = 1; i <= n; ++i) cout << color[i];
    cout << "\n";
    return 0;
}

/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
*/