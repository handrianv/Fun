/* 
    Sparse table
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

const int LOGN = 20;
const int MAXN = 2e5+5;
int st[MAXN][LOGN];
int logg[MAXN];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    logg[1] = 0;
    for(int i = 2; i < MAXN; ++i) logg[i] = logg[i/2] + 1;

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> st[i][0];
    } 

    for(int p = 1; p <= logg[n]; ++p)
    {
        for(int i = 0; i+(1<<p)-1 < n; ++i)
        {
            st[i][p] = min(st[i][p-1], st[i+(1<<(p-1))][p-1]);
        }
    }

    while(q--)
    {
        int left, right;
        cin >> left >> right;
        --left; --right;
        int j = logg[right-left+1];
        cout << min(st[left][j], st[right-(1<<j)+1][j]) << "\n";
    }
    return 0;
}   