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

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i].first;
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());

    int ans = 0;
    int currMin = 1e9;
    for(auto v : vec)
    {
        ans = max(ans, v.second - currMin);
        currMin = min(currMin, v.second);
    }

    if(ans == 0) ans = -1;
    cout << ans << "\n";
    return 0;
}   