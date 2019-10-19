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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 2e5+5;
int segtree[4*MAXN];
int arr[MAXN];
int n, m;

void Build(int curr, int left, int right)
{
    if(left == right)
    {
        segtree[curr] = arr[left];
        return;
    }
    int mid = left + (right-left) / 2;
    Build(curr*2, left, mid);
    Build(curr*2+1, mid+1, right);
    segtree[curr] = max(segtree[curr*2], segtree[curr*2+1]);
}

int Query(int curr, int left, int right, int limit)
{
    if(segtree[curr] < limit) return 0;
    if(left == right) return (left+1);
    int mid = left + (right-left) / 2;
    if(segtree[curr*2] >= limit) return Query(curr*2, left, mid, limit);
    else if(segtree[curr*2+1] >= limit) return Query(curr*2+1, mid+1, right, limit);
}

void Update(int curr, int left, int right, int updateIdx, int updateVal)
{
    if(left == right)
    {
        segtree[curr] -= updateVal; 
        return;
    }
    int mid = left + (right-left) / 2;
    if(updateIdx <= mid) Update(curr*2, left, mid, updateIdx, updateVal);
    else Update(curr*2+1, mid+1, right, updateIdx, updateVal);
    segtree[curr] = max(segtree[curr*2], segtree[curr*2+1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    Build(1, 0, n-1);
    while(m--)
    {
        int limit;
        cin >> limit;
        int ans = Query(1, 0, n-1, limit);
        if(ans > 0) Update(1, 0, n-1, ans-1, limit);
        cout << ans;
        (m == 0) ? cout << "\n" : cout << " ";
    }
    return 0; 
}           