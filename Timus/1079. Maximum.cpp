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
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<int> vec(100005);
    vec[1] = 1;
    for(int i = 1; i <= 50000; ++i)
    {
        vec[i*2] += vec[i];
        vec[i*2+1] += vec[i];
        if(i > 1) vec[i*2-1] += vec[i];
    }
    for(int i = 2; i < 100000; ++i) vec[i] = max(vec[i], vec[i-1]);

    int n;
    cin >> n;
    while(n != 0)
    {
        cout << vec[n] << "\n";
        cin >> n;
    }
    return 0; 
}       