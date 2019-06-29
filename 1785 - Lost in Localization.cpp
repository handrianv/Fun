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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    string ans;
    if(n <= 4) ans = "few";
    else if(n <= 9) ans = "several";
    else if(n <= 19) ans = "pack";
    else if(n <= 49) ans = "lots";
    else if(n <= 99) ans = "horde";
    else if(n <= 249) ans = "throng";
    else if(n <= 499) ans = "swarm";
    else if(n <= 999) ans = "zounds";
    else ans = "legion";
    cout << ans << "\n";
    return 0;
}   