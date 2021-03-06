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
typedef pair<string, int> psi;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    unordered_map<string, int> cnt, price;
    int mx = 0;

    for(int i = 0; i < 6; ++i)
    {
        string trash, name;
        int p;
        cin >> trash >> name >> p;
        ++cnt[name];
        (cnt[name] == 1) ? price[name] = p : price[name] = min(price[name], p);
        mx = max(mx, cnt[name]);
    }

    int ans = 1e9;
    string ans2;
    for(const auto& kv : price)
    {
        if(cnt[kv.first] == mx)
        {
            if(ans > kv.second)
            {
                ans = kv.second;
                ans2 = kv.first;
            }
        }
    }
    cout << ans2 << "\n";
    return 0; 
}       