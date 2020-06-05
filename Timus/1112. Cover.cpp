/* 
    Interval scheduling problem
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bool Compare(const pi& p1, const pi& p2)
{
    if(p1.second == p2.second) return (p1.first < p2.first);
    return (p1.second < p2.second);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i].first >> vec[i].second;
        if(vec[i].first > vec[i].second) swap(vec[i].first, vec[i].second);
    }

    sort(vec.begin(), vec.end(), Compare);

    vector<pi> ans;
    for(int i = 0; i < n; ++i)
    {
        if(ans.empty() || ans.back().second <= vec[i].first)
        {
            ans.push_back(vec[i]);
        }
    }

    cout << ans.size() << "\n";
    for(auto& interval : ans)
    {
        cout << interval.first << " " << interval.second << "\n";
    }
    return 0;  
}

/*
Does order matter? Try sorting
Array bounds, overflow
Reverse the problem, try solving backwards
*/
