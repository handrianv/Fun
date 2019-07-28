/* 
    Books are put with binders facing outside. So first page is on right side and last page on left
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c >= d)
    {
        int n = c-d+1;
        cout << ((n-1)*2*b + n*a) << "\n";
    }
    else
    {
        int n = d-c+1;
        cout << ((n-1)*2*b + (n-2)*a) << "\n";
    }
    return 0;
}   