/* 
    The input K is useless :)
*/

#include <stdio.h>
#include <bits/stdc++.h>
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    ll n, k, ans = 0;
    cin >> n >> k;
    int id;
    while(cin >> id)
    {
        int sz;
        cin >> sz;
    
        ll curr = 0;
        for(int i = 0; i < sz; ++i)
        {
            ll trash, sz2;
            cin >> trash >> sz2;
            ans += (curr * sz2);
            curr += sz2;
        }
    }
    cout << ans << "\n";
    return 0;
}   