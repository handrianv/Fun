/* 
    Two approach:
    1. P is at most ~44720; Any larger and the arithmetic progression is guaranteed to exceed 1e9.
       We can just try every possible length. For every length, we can binary search the A to check whether it's possible or not.

    2. Write the equation as P*(2A+P-1) = 2*N.
       Now we know P must be divisor of 2*N, so we can try every divisor D and check whether A can be an integer if (2A+P-1) == (2*N)/D.

    This solution uses approach 1
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

ll n;

ll Check(ll len)
{
    ll left = 1, right = n;
    while(left <= right)
    {
        ll mid = left + (right-left) / 2;
        ll ap = len*(mid+mid+len-1) / 2;
        if(ap == n) return mid;
        (ap > n) ? right = mid-1 : left = mid+1;
    } 
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(ll len = 44720; len > 0; --len)
    {
        ll ans = Check(len);
        if(ans != -1)
        {
            cout << ans << " " << len << "\n";
            return 0;
        }
    }
    return 0;
}   