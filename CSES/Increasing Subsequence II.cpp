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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MOD = 1e9+7;
const int MAXN = 2e5+5;
int arr[MAXN], cpy[MAXN];
int fenwick[MAXN];
int n;

int Query(int idx)
{
    int ans = 0;
    while(idx > 0)
    {
        ans += fenwick[idx];
        if(ans >= MOD) ans -= MOD;
        idx -= LSOne(idx);
    }
    return ans;
}

void Update(int idx, int val)
{
    while(idx <= n)
    {
        fenwick[idx] += val;
        if(fenwick[idx] >= MOD) fenwick[idx] -= MOD;
        idx += LSOne(idx);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        cpy[i] = arr[i];
    }

    sort(cpy, cpy+n);
    for(int i = 0; i < n; ++i) arr[i] = lower_bound(cpy, cpy+n, arr[i]) - cpy + 1;
    
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int temp = Query(arr[i]-1) + 1;
        if(temp >= MOD) temp -= MOD;
        ans += temp;
        if(ans >= MOD) ans -= MOD;
        Update(arr[i], temp);
    }
    cout << ans << "\n";
    return 0; 
}           