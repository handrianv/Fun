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

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

const int MAXN = 1e5+5;
pi segtree[4*MAXN];
int cnt[4*MAXN];
int arr[MAXN];
int n, K;

bool cmp(pi p1, pi p2)
{
    if(p1.first == p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
}

void build(int node, int left, int right)
{
    if(left == right)
    {
        segtree[node] = pi(arr[left], left);
        cnt[node] = 1;
        return;
    }

    int mid = left + (right-left)/2;
    build(node*2, left, mid);
    build(node*2+1, mid+1, right);
    segtree[node] = max(segtree[node*2], segtree[node*2+1], cmp);
    cnt[node] = cnt[node*2] + cnt[node*2+1];
}

void update(int node, int left, int right, int idx)
{
    if(left == right)
    {
        segtree[node] = pi(-1, -1);
        cnt[node] = 0;
       // cout << "updateing " << idx << endl;
        return;
    }
    int mid = left + (right-left)/2;

    if(idx <= mid) 
        update(node*2, left, mid, idx);
    else 
        update(node*2+1, mid+1, right, idx);

    segtree[node] = max(segtree[node*2], segtree[node*2+1], cmp);
    cnt[node] = cnt[node*2] + cnt[node*2+1];
}

pi query(int node, int left, int right, int k)
{
    if(left == right) return segtree[node];
    int mid = left + (right-left)/2;
    pi ans;
    if(cnt[node*2] >= k)
        ans = query(node*2, left, mid, k);
    else    
        ans = max(segtree[node*2], query(node*2+1, mid+1, right, k-cnt[node*2]), cmp);
    return ans;
}

int dist(int node, int left, int right, int idx)
{
    if(left == right) return 1;
    int mid = left + (right-left)/2;
    int res = 0;
    if(idx > mid)
        res = cnt[node*2] + dist(node*2+1, mid+1, right, idx);
    else
        res = dist(node*2, left, mid, idx);
    return res;
}


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> K;
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    build(1, 0, n-1);
    for(int i = 0; i < n; ++i)
    {
        pi res = query(1, 0, n-1, K+1);
      //  cout << "res " << res.first << " " << res.second << endl;
        ans[i] = res.first;
      //  cout << "dist " << dist(1, 0, n-1, res.second) << endl;
        K -= (dist(1, 0, n-1, res.second)-1);
        update(1, 0, n-1, res.second);
      //  cout << "cnt " << cnt[1] << endl;
    }
    for(int i = 0; i < n; ++i)
    {
        cout << ans[i];
        (i == n-1) ? cout << endl : cout << " ";
    }
    return 0;
}   