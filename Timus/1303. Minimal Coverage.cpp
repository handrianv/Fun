/*
    Consider all intervals that can cover point 0. From these intervals, we should choose one with the rightmost endpoint. Repeat this until we cover point M.
    It's easy to prove that choosing such an interval is at least no worse, and can be better, than choosing interval with smaller left endpoint.
*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <bitset>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int m;
    cin >> m;
    vector<pi> intervals; intervals.reserve(1e5+5);
    int l, r;
    while(cin >> l >> r)
    {
        if(l == 0 && r == 0) break;
        intervals.push_back({l, r});
    }

    sort(intervals.begin(), intervals.end());

    int curr = 0; 
    vector<pi> ans; ans.reserve(1e5+5);
    ans.push_back({-1, -1});

    // Curr: current point we need to cover. Ans.back() -> Interval that can cover curr with max right endpoint
    for(auto& interval : intervals)
    {
        if(interval.first > curr)
        {
            if(ans.back().second < interval.first) break;
            curr = ans.back().second;
            ans.push_back(interval);
        }
        
        if(interval.second > ans.back().second)
        {
            ans.back() = interval;
            if(ans.back().second >= m) break;
        }
    }

    if(ans.back().second < m) cout << "No solution";
    else
    {
        cout << ans.size() << "\n";
        for(auto& interval : ans) cout << interval.first << " " << interval.second << "\n";
    }
    
    return 0;
}
     
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/