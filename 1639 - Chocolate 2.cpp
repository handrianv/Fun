/*
    There are (r-1) row to cut, resulting in r row of (c-1) column to cut. So total number of cut is (r-1) + (r * (c-1)) --> rc-1
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
    int m, n;
    cin >> m >> n;
    ((n*m-1) % 2 != 0) ? cout << "[:=[first]\n" : cout << "[second]=:]\n";
    return 0;
}   