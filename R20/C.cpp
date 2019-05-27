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
int n, k;
int arr[MAXN];

bool check(int target)
{
    int limit = k;
    int leftMost = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i+1 == n || arr[i+1] - arr[leftMost] > target)
        {
            if(limit == 0) return false;
            --limit;
            int nextLeft = i+1;
            while(nextLeft < n && arr[nextLeft] - arr[i] <= target) ++nextLeft;
            if(nextLeft < n && limit == 0) return false;
            leftMost = nextLeft;
            i = leftMost-1;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    int left = 0, right = 1e9;
    int ans = 0;
  
    while(left <= right)
    {
        int mid = left + (right-left) / 2;
        if(check(mid))
        {
            ans = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    cout << ans << "\n";
    return 0;
}   