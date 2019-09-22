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
    vector<int> money = {10, 50, 100, 500, 1000, 5000};
    int sum = 0, lowest = 1e9;

    for(int i = 0; i < 6; ++i)
    {
        int cnt;
        cin >> cnt;
        sum += (cnt * money[i]);
        if(cnt > 0) lowest = min(lowest, money[i]);
    }

    int price;
    cin >> price;
    int most = sum / price;
    int least = (sum-lowest) / price;
    ++least;

    cout << (most-least+1) << "\n";
    for(int i = least; i <= most; ++i)
    {
        cout << i;
        (i == most) ? cout << "\n" : cout << " ";
    }
    return 0; 
}       