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
typedef pair<ll, int> pli;

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

const int MAXN = 1e5;
int n;
int fenwick[MAXN+5];

void add(int idx, int val)
{
    while(idx <= n)
    {
        fenwick[idx] += val;
        idx += LSOne(idx);
    }
}

int query(int limit)
{
    int res = 0;
    while(limit > 0)
    {
        res += fenwick[limit];
        limit -= LSOne(limit);
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
    vector<int> cpy = vec;
    sort(cpy.begin(), cpy.end());
    for(int i = 0; i < n; ++i) vec[i] = lower_bound(cpy.begin(), cpy.end(), vec[i]) - cpy.begin() + 1;
    for(int i = 1; i < n-1; ++i) add(vec[i], 1);

    int left = 0, right = n-1;
    int ans = (n < 2) ? 1 : 2;
    while(left+1 < right)
    {
        int limit = min(vec[left], vec[right]);
        ans = max(ans, query(limit) + 2);
        if(vec[left] < vec[right])
        {
            int ori = vec[left];
            while(left < n && vec[left] <= ori)
            {
                ++left;
                if(left < n) add(vec[left], -1);
            }
        }
        else
        {
            int ori = vec[right];
            while(right>= 0 && vec[right] <= ori)
            {
                --right;
                if(right >= 0) add(vec[right], -1);
            }
        }   
    }
    cout << ans << "\n";
    return 0;
}   

