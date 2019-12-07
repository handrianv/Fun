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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const ll MOD = 1000000000000000007;
int n, m, k;

vector<vector<ll>> MatMul(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> ans(n, vector<ll>(n, MOD));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                ll temp = a[i][k] + b[k][j];
                ans[i][j] = min(ans[i][j], temp);
            }
        }
    }
    return ans;
}

vector<vector<ll>> MatPow(vector<vector<ll>> base, ll p)
{
    vector<vector<ll>> ans(n, vector<ll>(n, MOD));
    for(int i = 0; i < n; ++i) ans[i][i] = 0;
 
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
    cin >> n >> m >> k;
    vector<vector<ll>> adjMat(n, vector<ll>(n, MOD));
    for(int i = 0; i < m; ++i)
    {
        int a, b; ll c;
        cin >> a >> b >> c;
        --a; --b;
        adjMat[a][b] = min(adjMat[a][b], c);
    }
    ll ans =  MatPow(adjMat, k)[0][n-1];
    if(ans == MOD) ans = -1;
    cout << ans << "\n";
    return 0; 
}
