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
#include <cstring>
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
 
const int MAXN = 2e5+5;
int arr[MAXN], sorted[MAXN], fenwick[MAXN];
queue<int> occurences[MAXN];
int n, q;
 
void Update(int idx, int val)
{
    while(idx <= n)
    {
        fenwick[idx] += val;
        idx += LSOne(idx);
    }
}
 
int Query(int idx)
{
    int ans = 0;
    while(idx > 0)
    {
        ans += fenwick[idx];
        idx -= LSOne(idx);
    }
    return ans;
}
 
int Query(int left, int right)
{
    return (Query(right) - ((left == 0) ? 0 : Query(left-1)));
}
 
void Compress()
{
    sort(sorted+1, sorted+1+n);
    for(int i = 1; i <= n; ++i)
    {
        arr[i] = lower_bound(sorted+1, sorted+1+n, arr[i]) - (sorted + 1);
        occurences[arr[i]].push(i);
        if(occurences[arr[i]].size() == 1) Update(i, 1);
    } 
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    } 
    Compress();
 
    vector<pair<pi, int>> queries(q);
    for(int i = 0; i < q; ++i)
    {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());
    int lastLeft = 1;
    vector<int> ans(q);
    for(const auto& q : queries)
    {
        int left = q.first.first, right = q.first.second, qIdx = q.second;
        while(lastLeft < left)
        {
            occurences[arr[lastLeft]].pop();
            if(!occurences[arr[lastLeft]].empty()) Update(occurences[arr[lastLeft]].front(), 1);
            ++lastLeft;
        }
        ans[qIdx] = Query(left, right);
    }    
 
    for(int i = 0; i < q; ++i) cout << ans[i] << "\n";
    return 0; 
}