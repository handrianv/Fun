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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
const int MAXN = 1e6+5;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<int> vec(MAXN);
    for(int i = 1; i < MAXN; ++i)
    {
        for(int j = i+i; j < MAXN; j += i)
        {
            vec[j] += i;
        }
    }

    int left, right, ans;
    cin >> left >> right;
    double t = 1e9+7;

    for(int i = left; i <= right; ++i)
    {
        double temp = (double)vec[i] / i;
        if(temp < t)
        {
            t = temp;
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}