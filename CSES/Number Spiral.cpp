/* 
    Suppose y > x
    If we're at row y that means we've already traversed the previous (y-1) * (y-1) squares
    If we're at an odd row, we simply move 1 down and (x-1) to the right. If even we do y step down then (y-x) step left
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
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    cin >> t;
    while(t--)
    {
        ll ans = 0;
        ll y, x;
        cin >> y >> x;
        if(y > x)
        {
            ans = (y-1) * (y-1);
            if(y % 2 != 0) ans += x; else ans += (2*y-x);
        }
        else
        {
            ans = (x-1) * (x-1);
            if(x % 2 == 0) ans += y; else ans += (2*x-y);
        }
        cout << ans << "\n";
    }
    return 0; 
}           