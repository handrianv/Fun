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

const int MAXN = 2e5+5;
ll fenwick[MAXN];
int arr[MAXN];
int n, q;

void Add(int idx, int val)
{
    while(idx <= n)
    {
        fenwick[idx] += val;
        idx += LSOne(idx);
    }
}

ll Query(int idx)
{
    ll res = 0;
    while(idx > 0)
    {
        res += fenwick[idx];
        idx -= LSOne(idx);
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            Add(a, u); Add(b+1, -u);
        }
        else
        {
            int k;
            cin >> k;  
            ll ans = Query(k) + arr[k];
            cout << ans << "\n"; 
        }
    }
    return 0; 
}
