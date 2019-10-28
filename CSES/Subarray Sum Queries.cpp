/* 
    Store 4 information in segment tree node:
    A. Maximum subarray sum
    B. Maximum prefix sum
    C. Maximum suffix sum
    D. Sum

    Recurrence:
    A
    Either the maximum subarray lies entirely within left / right node, or it lies in both of them
    If it lies in both of them, then for it to be maximum we want to take as large possible suffix from left node, and as large possible prefix from right node
    So A[currentNode] = max(A[leftNode], A[rightNode], C[leftNode] + B[rightNode])

    B
    Either the maximum prefix sum lies entirely in the left node, or it includes the whole left and some (possibly all) part of right node
    If it includes the right node, for it to be maximum we want to take the maximum possible prefix from right node
    So B[currentNode] = max(B[leftNode], D[leftNode] + B[rightNode])

    Recurrence for C is similar to B and D is just normal sum segment tree.
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
ll preftree[4*MAXN], sufftree[4*MAXN], anstree[4*MAXN], sumtree[4*MAXN];
int arr[MAXN];
int n, m;

void Calc(int curr, int left, int right, int mid)
{
    anstree[curr] = max(anstree[curr*2], max(anstree[curr*2+1], sufftree[curr*2] + preftree[curr*2+1]));
    preftree[curr] = max(preftree[curr*2], sumtree[curr*2] + preftree[curr*2+1]);
    sufftree[curr] = max(sufftree[curr*2+1], sumtree[curr*2+1] + sufftree[curr*2]);
    sumtree[curr] = sumtree[curr*2] + sumtree[curr*2+1];
}

void Build(int curr, int left, int right)
{
    if(left == right)
    {
        preftree[curr] = sufftree[curr] = anstree[curr] = sumtree[curr] = arr[left];
        return;
    }
    int mid = left + (right-left) / 2;
    Build(curr*2, left, mid);
    Build(curr*2+1, mid+1, right);
    Calc(curr, left, right, mid);
}

void Update(int curr, int left, int right, int idx, int val)
{
    if(left == right)
    {
        preftree[curr] = sufftree[curr] = anstree[curr] = sumtree[curr] = val;
        return;
    }
    int mid = left + (right-left) / 2;
    if(idx <= mid) Update(curr*2, left, mid, idx, val);
    else Update(curr*2+1, mid+1, right, idx, val);
    Calc(curr, left, right, mid);
}

 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    Build(1, 0, n-1);
    while(m--)
    {
        int k, x;
        cin >> k >> x;
        --k;
        Update(1, 0, n-1, k, x);
        arr[k] = x;
        cout << anstree[1] << "\n";
    }
    return 0; 
}          