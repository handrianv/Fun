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

const int MAXN = 105;
int n;
int board[MAXN+5][MAXN+5];

bool Valid(int row, int cols)
{
    return (row >= 0 && row < n && cols >= 0 && cols < n);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> board[i][j];

    int startRow = -1, startCols = 0, printed = 0;
    while(printed < n*n)
    {
        (startRow+1 < n) ? ++startRow : ++startCols;
        int cpyRow = startRow, cpyCols = startCols;
        
        while(Valid(cpyRow, cpyCols))
        {
            cout << board[cpyRow][cpyCols];
            ++printed;
            (printed == n*n) ? cout << "\n" : cout << " ";
            --cpyRow; ++cpyCols;
        }
    }
    return 0;
}   