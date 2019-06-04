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
    vector<ll> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end());

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int k = i+2;
        for(int j = i+1; j < n; ++j)
        {
            while(k < n && vec[i]+vec[j] > vec[k]) ++k;
            ans += (k-j-1);
        }
    }
    cout << ans << "\n";
    return 0;
}   