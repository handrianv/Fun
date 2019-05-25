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

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int a, b;
    cin >> a >> b;
    --a; --b;
    int mult2 = b/2 - ((a>0) ? (a-1)/2 : 0);
    int mult3 = b/3 - ((a>0) ? (a-1)/3 : 0);
    int multBoth = b/6 - ((a>0) ? (a-1)/6 : 0);
    int ans = (b-a+1) - (mult2+mult3-multBoth) - (a == 0);
    cout << ans << endl;
    return 0;
}   