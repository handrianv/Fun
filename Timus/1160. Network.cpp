/*
    A slight modification of minimum spanning tree, where the cost of tree is not the sum of weights but the maximal weight over all edges.
    The usual kruskal algorithm still works. Recall that in kruskal we iterate edges in sorted weight.

    If we want the cost of our tree to be, say, 5, then it's clear that we should just use all edges from 1 to 4. There s no reason not to use them,
    since it will increase the "connectedness" of the tree while not increasing the answer.

    So we can just iterate edges in sorted weight, add them all greedily until we have a spanning tree.
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
#define EPS 1e-9
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1005;
int par[MAXN];
int cc = 0;

int FindSet(const int& x)
{
    return ((par[x] == x) ? x : par[x] = FindSet(par[x]));
}

bool Union(const int& x, const int& y)
{
    int a = FindSet(x), b = FindSet(y);
    if(a != b)
    {
        --cc;
        par[a] = b;
    }
    return (a != b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) par[i] = i;

    vector<pair<int, pi>> edges(m);
    for(auto& v : edges)
    {
        cin >> v.second.first >> v.second.second >> v.first;
    }

    sort(edges.begin(), edges.end());
    cc = n; int ansVal = 1e9;
    vector<pi> ans; ans.reserve(m);

    for(auto& edge : edges)
    {
        if(Union(edge.second.first, edge.second.second))
        {
            ansVal = edge.first;
            ans.push_back(edge.second);
        }
        if(cc == 1) break;
    }

    cout << ansVal << "\n" << ans.size() << "\n";
    for(auto& edge : ans)
    {
        cout << edge.first << " " << edge.second << "\n";
    }
    return 0;
}
 
/*
 
*/  