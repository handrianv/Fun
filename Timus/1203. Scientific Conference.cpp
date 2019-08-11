/* 
    Interval scheduling problem.
    https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pearson/04GreedyAlgorithms-2x2.pdf
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end(), [](pi a, pi b)
    {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    vector<pi> ans;
    for(const auto& interval : vec)
    {
        if(ans.empty() || interval.first > ans.back().second)
        {
            ans.push_back(interval);
        }
    }
    cout << ans.size() << "\n";
    return 0;
}   