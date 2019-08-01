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
    int n;
    cin >> n;
    int exc = 0, sat = 0, sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int score;
        cin >> score;
        sum += score;
        exc += (score == 5);
        sat += (score == 3);
    }

    if(sat) cout << "None\n";
    else if(exc == n) cout << "Named\n";
    else if(sum >= 4.5*n) cout << "High\n";
    else cout << "Common\n";
    return 0;
}   