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


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, ans = 0;
    cin >> n;
    while(n > 0)
    {
        int cpy = n;
        int maxD = 0;
        while(cpy > 0)
        {
            int d = cpy % 10;
            cpy /= 10;
            maxD = max(maxD, d);
        }
        n -= maxD;
        ++ans;
    }
    cout << ans << "\n";
    return 0; 
}           