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
    int row; char cols;
    cin >> row >> cols;

    if(row >= 1 && row <= 2)
    {
        if(cols == 'A' || cols == 'D') cout << "window\n";
        else cout << "aisle\n";
    }
    else if(row >= 3 && row <= 20)
    {
        if(cols == 'A' || cols == 'F') cout << "window\n";
        else cout << "aisle\n";
    }
    else
    {
        if(cols == 'A' || cols == 'K') cout << "window\n";
        else if(cols == 'C' || cols == 'D' || cols == 'G' || cols == 'H') cout << "aisle\n";
        else cout << "neither\n";
    }
    return 0;
}   