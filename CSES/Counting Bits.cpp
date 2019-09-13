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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 52; i >= 0; --i)
    {
        if(n & (1LL << i))
        {
            ans += ((1LL << i) * i / 2); // Use zero on this bit
            ans += (n - (1LL << i) + 1); // Use one
            n -= (1LL << i);
        }
    }
    cout << ans << "\n";
    return 0; 
}       