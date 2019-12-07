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
vector<pair<int, pi>> edgeList; 
int par[MAXN];
int n, m;

int Find(int x)
{
    return (par[x] == x) ? x : par[x] = Find(par[x]);
}

bool IsSameSet(int x, int y)
{
    return (Find(x) == Find(y));
}

void Unite(int x, int y)
{
    int a = Find(x), b = Find(y);
    par[a] = b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    edgeList = vector<pair<int, pi>>(m);
    int numcc = n;
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList[i] = {c, {a, b}};
        par[a] = a; par[b] = b;
    }
    sort(edgeList.begin(), edgeList.end());
    ll ans = 0;
    for(auto& edge : edgeList)
    {
        int cost = edge.first, a = edge.second.first, b = edge.second.second;
        if(!IsSameSet(a, b))
        {
            --numcc;
            Unite(a, b);
            ans += cost;
        }
    }
    if(numcc != 1) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
    return 0; 
}