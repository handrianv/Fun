/* 
    Easy way
    Order statistic.

    Harder way
    Read all number (including queries) and compress them.
    Now it's standard fenwick tree problem. Just keep track of frequency of each number.
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

const int MAXN = 6e5+5;
int arr[MAXN], sorted[MAXN], fenwick[MAXN];
int n, q;

void Update(int idx, int val)
{
    while(idx <= n+2*q)
    {
        fenwick[idx] += val;
        idx += LSOne(idx);
    }
}

int Query(int idx)
{
    int res = 0;
    while(idx > 0)
    {
        res += fenwick[idx];
        idx -= LSOne(idx);
    }
    return res;
}

int Query(int left, int right)
{
    return Query(right) - ((left-1) == 0 ? 0 : Query(left-1));
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;

    vector<int> sorted;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sorted.push_back(arr[i]);
    }

    vector<pair<char, pi>> queries(q);
    for(int i = 0; i < q; ++i)
    {
       cin >> queries[i].first >> queries[i].second.first >> queries[i].second.second;
       if(queries[i].first == '?') sorted.push_back(queries[i].second.first); 
       sorted.push_back(queries[i].second.second);
    } 

    // Compress
    sort(sorted.begin(), sorted.end());
    for(int i = 0; i < n; ++i)
    {
       arr[i] = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1; 
       Update(arr[i], 1);
    } 
    for(int i = 0; i < q; ++i)
    {
        if(queries[i].first == '?') queries[i].second.first = lower_bound(sorted.begin(), sorted.end(), queries[i].second.first) - sorted.begin() + 1;
        queries[i].second.second = lower_bound(sorted.begin(), sorted.end(), queries[i].second.second) - sorted.begin() + 1;
    }
    
    for(const auto& query : queries)
    {
        char type = query.first;
        if(type == '!')
        {
            int k = query.second.first - 1;
            int x = query.second.second;
            Update(arr[k], -1);
            Update(x, 1);
            arr[k] = x;
        }
        else
        {
            cout << Query(query.second.first, query.second.second) << "\n";
        }
    }
    return 0; 
}           