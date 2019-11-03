/* 
    1. Segment tree
    Make a sum segment tree where initially all index have value 1, indicating this index hasn't been removed.
    For every removal, we can traverse down the tree left or right by checking if it has enough element
    Then we update the index to 0, indicating it has been removed

    2. Order statistic
    Straightforward with find_by_order

    3. Rope
    TODO: Learn
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

const int MAXN = 2e5+5;
int segtree[4*MAXN];
int arr[MAXN];
int n, q;

void Build(int curr, int left, int right)
{
    if(left == right)
    {
        segtree[curr] = 1;
        return;
    }
    int mid = left + (right-left) / 2;
    Build(curr*2, left, mid);
    Build(curr*2+1, mid+1, right);
    segtree[curr] = segtree[curr*2] + segtree[curr*2+1];
}

void Update(int curr, int left, int right, int updateIdx)
{
    if(left == right)
    {
        segtree[curr] = 0;
        return;
    }
    int mid = left + (right-left) / 2;
    if(updateIdx <= mid) Update(curr*2, left, mid, updateIdx);
    else Update(curr*2+1, mid+1, right, updateIdx);
    segtree[curr] = segtree[curr*2] + segtree[curr*2+1];
}

int Query(int curr, int left, int right, int q)
{
    if(left == right)
    {
        return left;
    } 
    int mid = left + (right-left) / 2;
    if(segtree[curr*2] >= q) return Query(curr*2, left, mid, q);
    else return Query(curr*2+1, mid+1, right, q-segtree[curr*2]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    Build(1, 0, n-1);

    for(int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        int ans = Query(1, 0, n-1, p);
        cout << arr[ans];
        (i == n-1) ? cout << "\n" : cout << " ";
        Update(1, 0, n-1, ans);
    }
    return 0; 
}           