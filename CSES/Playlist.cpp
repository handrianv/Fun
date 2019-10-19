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
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];

    map<int, int> cnt;
    int left = 0, ans = 0;
    for(int right = 0; right < n; ++right)
    {
        ++cnt[vec[right]];
        while(left < right && cnt[vec[right]] > 1)
        {
            --cnt[vec[left]];
            ++left;
        }
        ans = max(ans, right-left+1);
    }
    cout << ans << "\n";
    return 0; 
}           