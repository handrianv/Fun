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
    map<string, int> m;
    while(n--)
    {
        string str;
        cin >> str;
        ++m[str];
    }
    for(auto kv : m) if(kv.second >= 2) cout << kv.first << "\n";
    return 0;
}   