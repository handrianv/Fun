/*
*/

#include <stdio.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 2e5+5;
ll fenwick[MAXN];
ll arr[MAXN];
int n, q;

void Update(int idx, int inc)
{
    while(idx <= n)
    {
        fenwick[idx] += inc;
        idx += LSOne(idx);
    }
}

ll Query(int idx)
{
    ll ans = 0;
    while(idx > 0)
    {
        ans += fenwick[idx];
        idx -= LSOne(idx);
    }
    return ans;
}

ll Query(int left, int right)
{
    return (Query(right) - ((left == 1) ? 0: Query(left-1)));
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        Update(i, arr[i]);
    }

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int k, u;
            cin >> k >> u;
            Update(k, u-arr[k]);
            arr[k] = u;
        }
        else
        {
            int left, right;
            cin >> left >> right;
            cout << Query(left, right) << "\n";
        }
    }
    return 0;
}