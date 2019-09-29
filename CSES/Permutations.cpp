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
    int n;
    cin >> n;
    if(n == 1) cout << "1\n";
    else if(n == 4) cout << "3 1 4 2\n";
    else if(n < 4) cout << "NO SOLUTION\n";
    else
    {
        for(int i = 1; i <= n; i += 2) cout << i << " ";
        for(int i = 2; i <= n; i += 2) cout << i << ((i + 2 > n) ? "\n" : " ");  
    }
    return 0; 
}       