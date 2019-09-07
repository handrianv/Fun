/* 
    Distribute them as evenly as possible.
    Proof:
    (1) Two teams, with k people each, contributes k^2 to the answer.
    (2) If you make them uneven, say to (k-x) and (k+x) it contributes k^2-x^2 which is less than k^2
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
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int big = ceil(n * 1.0 / k);
        int bigCnt = (n%k);
        int small = n / k;
        int smallCnt = k - bigCnt;
        cout << ((bigCnt * (bigCnt-1) / 2 * big * big) + (smallCnt * (smallCnt-1) / 2 * small * small) + (bigCnt * smallCnt * big * small)) << "\n";
    }
    return 0;
}