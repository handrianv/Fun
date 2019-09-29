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
    int n;
    cin >> n;
    vector<pi> vec(2*n); // {time, enter/leave}
    for(int i = 0; i < 2*n; ++i)
    {
        cin >> vec[i].first >> vec[++i].first;
        vec[i].second = 1;
    }
    sort(vec.begin(), vec.end());
    int curr = 0, ans = 0;
    for(const auto& v : vec)
    {
        if(v.second == 0) ++curr; else --curr;
        ans = max(ans, curr);
    }
    cout << ans << "\n";
    return 0; 
}       