/* 
    For a number i:
    -. Number of times it appears at the larger side of the domino is (i+1) times;
    -. Similarly, number of times it appears at the smaller side of the domino is (n-i+1) times;
    So a number i will take (n+2)*i diamonds.
    Answer is Sigma(i=0->n)((n+2)*i) ==  (n+2) * Sigma(i=0->n)(i) == (n+2) * (n*(n+1)/2)
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
    ll n;
    cin >> n;
    cout << ((n+2)*n*(n+1)/2) << "\n";
    return 0;
}   