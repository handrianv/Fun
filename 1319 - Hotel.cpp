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

int n;

bool Valid(int row, int cols)
{
    return (row >= 0 && row < n && cols >= 0 && cols < n);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    int startRow = 0, startCols = n-1, printed = 0;

    while(printed < n*n)
    {
        int cpyRow = startRow, cpyCols = startCols;
        while(Valid(cpyRow, cpyCols))
        {
            ans[cpyRow][cpyCols] = (++printed);
            ++cpyRow; ++cpyCols;
        }

        (startCols-1 >= 0) ? --startCols : ++startRow;
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << ans[i][j];
            (j == n-1) ? cout << "\n" : cout << " ";
        }
    }
    return 0;
}   