/* 
    Inclusion-Exclusion
    Inclusion: 
        Number of ways to put knight regardless of attacking each other or not -> n*(n-1) / 2 where n is k^2
    Exclusion: 
        Number of ways to put knight where they attack each other. 
        They must be in L-shaped 2x3 or 3x2 squares so there are 2*(k-1)*(k-2) ways to put them. For each way the knight can be swapped between upper-left and lower-right so multiply by two again.
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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; ++i)
    {
        ll totalSquare = i * i;
        ll ans = totalSquare * (totalSquare-1) / 2;
        ll exclusion = 4 * (i-1) * (i-2);
        ans -= exclusion;
        cout << ans << "\n";
    }
    return 0; 
}           