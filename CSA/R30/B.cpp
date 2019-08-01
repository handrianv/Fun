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

bool exist[2500];

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        exist[num] = true;
    }

    int ans = 0;
    int countExist = 0;
    for(int i= 1; i <= k; ++i) if(exist[i]) ++countExist;
    if(countExist+m >= k) ++ans;
    for(int i = k+1; i <= 1000; ++i)
    {
        if(exist[i]) ++countExist;
        if(exist[i-k]) --countExist;
        ans += (countExist+m >= k);
    }
    cout << ans << "\n";
    return 0;
}   

