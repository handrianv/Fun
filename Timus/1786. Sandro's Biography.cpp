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
    string str, target = "Sandro";
    int ans = 1e9;
    cin >> str;

    for(int i = 0; i+5 < str.size(); ++i)
    {
        int cost = 0;
        for(int j = 0; j < 6; ++j)
        {
            cost += ( (isupper(str[i+j]) != isupper(target[j])) + (tolower(str[i+j]) != tolower(target[j])) );
        }
        ans = min(ans, cost);
    }
    cout << ans*5 << "\n";
    return 0; 
}       