/* 

*/

#include <iostream>
#include <iomanip>
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1e5+5;
int n, m, ans = 1, cc;
int par[MAXN], sz[MAXN];

int FindSet(int x)
{
    return (par[x] == x ? x : par[x] = FindSet(par[x]));
}

void Union(int a, int b)
{
    int x = FindSet(a), y = FindSet(b);
    if(x != y)
    {
        par[x] = y;
        --cc;
        sz[y] += sz[x];
        ans = max(ans, sz[y]);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    cc = n;
    for(int i = 1; i <= n; ++i)
    {
        par[i] = i;
        sz[i] = 1;
    } 
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
        cout << cc << " " << ans << "\n";
    }
    return 0; 
}
