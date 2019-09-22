/* 
    Sliding range maximum query
    Tutorial: https://wcipeg.com/wiki/Sliding_range_minimum_query
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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int m, n = 0;
    cin >> m;
    int num;
    cin >> num;
    deque<pi> deq; // {index, num}

    while(num != -1)
    {
        while(!deq.empty() && deq.back().second < num)
        {
            deq.pop_back();
        }
        deq.push_back({n, num});

        ++n;
        if(n >= m)
        {
            cout << deq.front().second << "\n";
            if(deq.front().first == n-m) deq.pop_front();
        } 
        cin >> num;
    }
    return 0; 
}       