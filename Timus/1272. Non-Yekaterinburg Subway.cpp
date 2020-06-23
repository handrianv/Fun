/*
    If tunnels are 0 and bridges are 1, then the problem is simply finding minimum spanning tree. However, the constraint of the problem allows several optimizations (assuming we're using Kruskal algorithm):
    -. Tunnels are always given first, so we can skip the sorting part of Kruskal.
    -. Answer is guaranteed to exist, so we can simply use all tunnel. After this, let the number of connected component be C. Then we can simply use (C-1) bridges. No need to finish the Kruskal. 
       These (C-1) bridges are guaranteed to exist, since if not then the answer doesn't exist.
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

const int MAXN = 1e4+5;
int par[MAXN];
int n, k, m;

int FindSet(int x)
{
    return (x == par[x] ? x : FindSet(par[x]));
}

bool Unite(int x, int y)
{
    int a = FindSet(x), b = FindSet(y);
    if(a == b) return false;
    par[a] = b;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> k >> m;
    for(int i = 1; i <= n; ++i) par[i] = i;
    
    int ans = n;
    for(int i = 0; i < k; ++i)
    {
        int a, b;
        cin >> a >> b;
        ans -= Unite(a, b);
    }

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
    }

    cout << (ans - 1) << "\n";
    return 0;
}
     
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/