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

bool Compare(pi a, pi b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end(), Compare);
    int ans = 0, currEnd = 0;
    for(const auto& interval : vec)
    {
        if(interval.first >= currEnd)
        {
            currEnd = interval.second;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0; 
}           