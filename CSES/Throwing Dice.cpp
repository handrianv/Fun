/* 
    
*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>
 
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
const ll MOD = 1e9+7;
 
vector<vector<ll>> MatMul(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> ans(6, vector<ll>(6));
    int k;
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            for(ans[i][j] = k = 0; k < 6; ++k)
            {
                ll temp = ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
                ans[i][j] = ((ans[i][j]) + (temp % MOD)) % MOD;
            }
        }
    }
    return ans;
}
 
 
vector<vector<ll>> MatPow(vector<vector<ll>> base, ll p)
{
    vector<vector<ll>> ans(base.size(), vector<ll>(base.size()));
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 6; ++j)
        {
            ans[i][j] = (i==j);
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
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<vector<ll>> base(6, vector<ll>(6));
    for(int j = 0; j < 6; ++j)
    {
        base[0][j] = 1;
        for(int k = 1; k <= 6; ++k)
        {
            if(j-k < 0) continue;
            base[0][j] += base[0][j-k];
        }
    }
 
    vector<vector<ll>> trans = {
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1}
    };
 
    ll n;
    cin >> n;
    cout << MatMul(base, MatPow(trans, max(0LL, n-6)))[0][min(5LL, n-1)] << "\n";
    return 0; 
}