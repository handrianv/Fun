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
typedef pair<ll, int> pli;

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
    vector<int> vec(n+2);
    vec[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> vec[i];
    vec[n+1] = 1e5+1;
    sort(vec.begin(), vec.end());

    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans = max(ans, vec[i+1]-1 - (vec[i-1]+1) + 1);
    }
    cout << ans << "\n";
    return 0;
}   

