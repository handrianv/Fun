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
 
const int MAXLOG = 31;
const int MAXN = 2e5+5;
int n, q;
int nxt[MAXN][MAXLOG];
 
void Preprocess()
{
    for(int i = 1; i < MAXLOG; ++i)
    {
        for(int node = 1; node <= n; ++node)
        {
            nxt[node][i] = nxt[nxt[node][i-1]][i-1];
        }
    }
}
 
int Query(int x, int k)
{
    int p = 0;
    while(k > 0)
    {
        if(k % 2 != 0)
        {
            x = nxt[x][p];
        }
        k /= 2;
        ++p;
    }
    return x;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> nxt[i][0];
    Preprocess();
    while(q--)
    {
        int x, k;
        cin >> x >> k;
        cout << Query(x, k) << "\n";
    }
    return 0; 
}