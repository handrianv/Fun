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

int Convert(char ch)
{
    if(ch == 'A' || ch == 'P' || ch == 'O' || ch == 'R') return 1;
    else if(ch == 'B' || ch == 'M' || ch == 'S' ) return 2;
    else return 3;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    int currCase = 1;
    int ans = 0;

    while(n--)
    {
        string str;
        cin >> str;
        int caseNumber = Convert(str[0]);
        ans += abs(currCase-caseNumber);
        currCase = caseNumber;
    }
    cout << ans << "\n";
    return 0;
}   