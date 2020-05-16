/* 
    -. If a segment (L, R) has even parity, then segment [1..R] and segment [1...(L-1)] must have the same parity.
    -. If a segment (L, R) has odd parity, then segment [1..R] and segment [1...(L-1)] must have different parity.
    Now we need to keep track which segments have the same parity, and which segments have different parity.

    This can be done with a modified disjoint set, similar to this problem:
    https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2498
    
    Idea in brief:
    For every node X we create a "shadow" node, let's call it X'. Every node that is the same set as X', it means that that node is in a different set from X.
    To indicate node Y is in a different set from node X, we do Union on X and Y', and also X' and Y.
    To indicate node Y is in the same set as node X, we do Union on X and Y, and also X' and Y'.
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 21005;
int par[MAXN];

void Build()
{
    for(int i = 0; i < MAXN; ++i) par[i] = i;
}

int FindSet(int x)
{
    return (x == par[x]) ? x : par[x] = FindSet(par[x]);
}

bool IsSameSet(int x, int y)
{
    return FindSet(x) == FindSet(y);
}

void Union(int x, int y)
{
    int a = FindSet(x), b = FindSet(y);
    par[a] = b;
}

int Shadow(int x)
{
    return x + 10002;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;

    while(n != -1)
    {
        int q;
        cin >> q;
        vector<int> sorted; sorted.reserve(2*q);
        vector<pair<pi, string>> queries(q);

        for(int i = 0; i < q; ++i)
        {
            int l, r; string type;
            cin >> l >> r >> type;
            sorted.push_back(l-1); sorted.push_back(r);
            queries[i] = {{l, r}, type};
        }

        sort(sorted.begin(), sorted.end());
        int ans = q;
        Build();

        for(int i = 0; i < q; ++i)
        {   
            int l = queries[i].first.first, r = queries[i].first.second; string type = queries[i].second;
            l = lower_bound(sorted.begin(), sorted.end(), l-1) - sorted.begin();
            r = lower_bound(sorted.begin(), sorted.end(), r) - sorted.begin();

            if(type == "even")
            {
                if(IsSameSet(l, Shadow(r)) || IsSameSet(Shadow(l), r))
                {
                    ans  = i;
                    break;
                }
                Union(l, r);
                Union(Shadow(l), Shadow(r));
            }
            else
            {
                if(IsSameSet(l, r) || IsSameSet(Shadow(l), Shadow(r)))
                {
                    ans  = i;
                    break;
                }
                Union(Shadow(l), r);
                Union(l, Shadow(r));
            }
        }

        cout << ans << "\n";
        cin >> n;
    }
    return 0;  
}