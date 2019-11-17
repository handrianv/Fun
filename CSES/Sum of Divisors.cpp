/*

*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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

const ll MOD = 1e9+7;

ll AP(ll first, ll last)
{
    ll cnt = last-first+1;
    ll s = first+last;
    if(cnt % 2 == 0) cnt /= 2; else s /= 2;
    cnt %= MOD; s %= MOD;
    return (cnt * s) % MOD;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    ll n;
    cin >> n;
    ll limit = sqrt(n);
    ll ans = 0;

    for(ll i = 1; i <= limit; ++i)
    {
        ll temp = ((n / i) * i) % MOD; // Divisor i can appear (n/i) times
        ans = (ans + temp) % MOD;
        if((n/i) > i)
        {
            temp = (AP(n/(i+1)+1, n/i) * i) % MOD; // Every number from floor(n/(i+1))+1 to n/i can appear i times.
            ans = (ans + temp) % MOD;
        }
    }
    cout << ans << "\n";
    return 0; 
}