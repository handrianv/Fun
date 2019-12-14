/* 
    dp[s] -> how many ways to make sum s
    Our target is s = sum of all numbers / 2
    TODO: Do it without mod inverse
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
 
const int MOD = 1e9+7;

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
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    int target = n*(n+1) / 2;
    if(target % 2 != 0) 
    {
        cout << "0\n";
        return 0;
    }
    target /= 2;
    vector<int> dp(target+5);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int sum = target; sum >= i; --sum)
        {
            dp[sum] += dp[sum-i];
            dp[sum] %= MOD;
        }
    }
    cout << (((ll)dp[target] * ModInverse(2)) % MOD) << "\n";
    return 0; 
}