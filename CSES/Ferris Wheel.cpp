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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, x;
    cin >> n >> x;
    multiset<int> s;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        s.insert(num);
    }

    int ans = 0;
    while(!s.empty())
    {
        ++ans;
        int largest = *(s.rbegin());
        s.erase(--s.end());
        int with = x-largest;
        auto iter = s.upper_bound(with);
        if(iter != s.begin()) 
            s.erase(--iter);
    }
    cout << ans << "\n";
    return 0;
}