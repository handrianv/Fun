/* 
    This is basically the O(n log n) algorithm for longest increasing subsequence
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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<int> vec;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        if(vec.empty() || num >= vec.back()) vec.push_back(num);
        else
        {
            auto iter = upper_bound(vec.begin(), vec.end(), num);
            *iter = num;
        }
    }
    cout << vec.size() << "\n";
    return 0; 
}           