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

const int MAXN = 2e5+5;
int segtree[4*MAXN];
int arr[MAXN];
int n, q;

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
    segtree[curr] = min(segtree[curr*2], segtree[curr*2+1]);
}

void Update(int curr, int left, int right, int idx)
{
    if(left == right)
    {
        segtree[curr] = arr[idx];
        return;
    }
    int mid = left + (right-left) / 2;
    (idx <= mid) ? Update(curr*2, left, mid, idx) : Update(curr*2+1, mid+1, right, idx);
    segtree[curr] = min(segtree[curr*2], segtree[curr*2+1]);
}

int Query(int curr, int left, int right, int qLeft, int qRight)
{
    if(left > qRight || right < qLeft) return 2e9;
    if(left >= qLeft && right <= qRight) return segtree[curr];
    int mid = left + (right-left) / 2;
    return min(Query(curr*2, left, mid, qLeft, qRight), Query(curr*2+1, mid+1, right, qLeft, qRight));
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    Build(1, 0, n-1);

    while(q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1)
        {
            arr[--a] = b;
            Update(1, 0, n-1, a);
        }
        else
        {
            cout << Query(1, 0, n-1, --a, --b) << "\n";
        }
    }
    return 0; 
}       