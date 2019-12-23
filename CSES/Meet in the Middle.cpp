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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
const int MAXN = 45;
int n, x;
int arr[MAXN];
 
vector<ll> Generate(int start, int sz)
{
    vector<ll> res((1<<sz));
    for(int i = 0; i < res.size(); ++i)
    {
        ll sum = 0;
        for(int j = 0; j < sz; ++j)
        {
            if(i & (1<<j)) sum += arr[start+j];
        }
        res[i] = sum;
    }
    return res;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> x;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
 
    vector<ll> s1 = Generate(0, n/2);
    vector<ll> s2 = Generate(n/2, n-n/2);
 
    ll ans = 0;
    sort(s2.begin(), s2.end());
    for(const auto& num : s1)
    {
        auto upper = upper_bound(s2.begin(), s2.end(), x-num);
        auto lower = lower_bound(s2.begin(), s2.end(), x-num);
        ans += (upper-lower);
    }
    cout << ans << "\n";
    return 0;
}        