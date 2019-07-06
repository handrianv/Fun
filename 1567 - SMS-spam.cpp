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

int Special(int ch)
{
    if(ch == '.' || ch == ' ') return 1;
    else if(ch == ',') return 2;
    else if(ch == '!') return 3;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    getline(cin, str);
    int ans = 0;

    for(auto ch : str)
    {
        if(isalpha(ch))
        {
            ans += (((ch-'a') % 3) + 1);
        }
        else
        {
            ans += Special(ch);
        }
    }
    cout << ans << "\n";
    return 0;
}   