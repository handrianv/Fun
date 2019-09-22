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
    vector<int> vec(3, 1), temp(3);
    for(int i = 0; i < 3; ++i) cin >> temp[i];
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i)
    {
        string str;
        cin >> str;
        if(str == "Blue") vec[0] = temp[0];
        else if(str == "Red") vec[1] = temp[1];
        else vec[2] = temp[2];
    }
    cout << (vec[0] * vec[1] * vec[2]) << "\n";
    return 0; 
}       