/* 
    TODO: can actually precompute inverse factorial
*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
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

const int MAXN = 1e6+5;
const ll MOD = 1e9+7;
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

void Precompute()
{
    fact[0] = 1;
    for(ll i = 1; i < MAXN; ++i)
    {
        fact[i] = (i*fact[i-1]) % MOD;
    }
}

ll Combination(int a, int b)
{
    ll nume = fact[a];
    ll denom = (fact[b] * fact[a-b]) % MOD;
    return ((nume * ModInverse(denom)) % MOD);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    Precompute();
    int n;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        cout << Combination(a, b) << "\n";
    }
    return 0; 
}