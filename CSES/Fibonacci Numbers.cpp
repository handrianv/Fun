/* 
    TODO: Create better matrix template
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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const ll MOD = 1e9+7;
const int MAXN = 2;
struct Matrix{
    ll mat[MAXN][MAXN];
    Matrix(){for(int i = 0; i < MAXN; ++i) for(int j = 0 ; j < MAXN; ++j) mat[i][j] = 0;}
};
 
Matrix MatMul(Matrix a, Matrix b)
{
    Matrix ans; int k;
    for(int i = 0; i < MAXN; ++i)
    {
        for(int j = 0; j < MAXN; ++j)
        {
            for(ans.mat[i][j] = k = 0; k < MAXN; ++k)
            {
                ll temp = ((a.mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD;
                ans.mat[i][j] = ((ans.mat[i][j]) + (temp % MOD)) % MOD;
            }
        }
    }
    return ans;
}
 
Matrix MatPow(Matrix base, ll p)
{
    Matrix ans;
    for(int i = 0; i < MAXN; ++i)
    {
        for(int j = 0; j < MAXN; ++j)
        {
            ans.mat[i][j] = (i==j);
        }
    }
 
    while(p)
    {
        if(p&1) ans = MatMul(ans, base);
        base = MatMul(base, base);
        p /= 2;
    }
 
    return ans;
}


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    Matrix base, trans;
    base.mat[0][1] = 1;
    trans.mat[0][1] = trans.mat[1][0] = trans.mat[1][1] = 1;

    ll n;
    cin >> n;
    if(n == 0) cout << "0\n";
    else cout << MatMul(base, MatPow(trans, n-1)).mat[0][1] << "\n";
    return 0; 
}           