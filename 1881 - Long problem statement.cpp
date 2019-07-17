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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int h, w, n;
    cin >> h >> w >> n;
    int ans = 1, currCols = 0, currRow = 0;

    while(n--)
    {
        string str;
        cin >> str;
        currCols += str.size();
        if(currCols > w)
        {
            ++currRow;
            currCols = str.size();
        }
        ++currCols;
        if(currRow == h)
        {
            currRow = 0;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}   