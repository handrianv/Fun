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
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


ll n, x, y;
int move_x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int move_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int k_move_x[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int k_move_y[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
string names[5] = {"King", "Knight", "Bishop", "Rook", "Queen"};
ll ans[5];

bool Valid(int currx, int curry)
{
    return (currx >= 1 && currx <= n && curry >= 1 && curry <= n);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> x >> y;

    for(int i = 0; i < 8; ++i)
    {
        if(Valid(x+move_x[i], y+move_y[i])) ++ans[0];
    }

    for(int i = 0; i < 8; ++i)
    {
        if(Valid(x+k_move_x[i], y+k_move_y[i])) ++ans[1];
    }

    ans[2] = min(n-x, n-y) + min(x-1, n-y) + min(n-x, y-1) + min(x-1, y-1);
    ans[3] = (n-x)+(x-1)+(n-y)+(y-1);
    ans[4] = ans[2] + ans[3];

    for(int i = 0; i < 5; ++i)
    {
        cout << names[i] << ": " << ans[i] << "\n";
    }
    return 0;
}      