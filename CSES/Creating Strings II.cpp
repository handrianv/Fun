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
 
const ll MOD = 1e9+7;

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

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<ull> fact(1e6+5);
    fact[0] = 1;
    for(int i = 1; i <= 1e6; ++i) fact[i] = (i * fact[i-1]) % MOD;

    string str;
    cin >> str;
    vector<int> cnt(30);
    for(auto ch : str) ++cnt[ch-'a'];
    ll ans = fact[str.size()];
    for(int i = 0; i < 26; ++i) ans = (ans * ModInverse(fact[cnt[i]])) % MOD;
    cout << ans << "\n";
    return 0; 
}       