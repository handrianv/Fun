/* 
    Note: "==" means congruence here

    From fermat's little theorem:
    (1)   a^p == a (mod p), when p is prime
    Rearranging:
    (2)   a * (a^(p-1) - 1) == 0 (mod p)
    When a and p coprime, it means that p | (a^(p-1)-1), so:
    (3)   a^(p-1) == 1 (mod p)
    From this, we can derive that for any power x:
    (4)  a^x == a^(x mod (p-1)) (mod p)

    ** Note to self: try to derive again yourself before reading below **

    First, write x as k*(p-1) + r. Then:
    (5)   a^(k*(p-1) + r) -> a^(k*(p-1)) * a^r
    From (3), we know that a^(k*(p-1)) == 1 (mod p), then:
    (6)   a^x == 1 * a^r (mod p)
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    while(n--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll x = ModExponent(b, c, MOD-1);
        ll res = ModExponent(a, x, MOD);
        cout << res << "\n";
    }
    return 0;
}   