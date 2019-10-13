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
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MOD = 1e9+7;
const int MAXN = 2e6+5;
ll fact[MAXN];

ll ModExponent(ll base, ll exponent, ll m)
{
    ll result = 1;
    while(exponent > 0)
    {
        if(exponent % 2 != 0)
        {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exponent /= 2;
    }
    return result;
}

ll ModInverse(ll x)
{
    return ModExponent(x, MOD-2, MOD);
}

ll Combination(ll n, ll r)
{
    ll nume = fact[n];
    ll denom = (fact[r] * fact[n-r]) % MOD;
    return ((nume * ModInverse(denom)) % MOD);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    fact[0] = 1;
    for(int i = 1; i < MAXN; ++i) fact[i] = (i * fact[i-1]) % MOD;
    ll n, m;
    cin >> n >> m;
    cout << Combination(n+m-1, m) << "\n";
    return 0; 
}           