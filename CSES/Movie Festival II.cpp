/* 
    Let's sort movie by finish time, then it's optimal to always try to watch movie with earliest finish time.
    Proof is similar to interval scheduling problem: https://en.wikipedia.org/wiki/Interval_scheduling
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
#define EPS 1e-9
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

bool Compare(pi a, pi b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;
    vector<pi> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end(), Compare);
    multiset<int> watching; // End time of people currently watching movie
    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        auto iter = watching.upper_bound(vec[i].first);
        if(iter != watching.begin())
        {
            --iter;
            ++ans;
            watching.erase(iter);
            watching.insert(vec[i].second);
        }
        else if(k > 0)
        {
            --k;
            ++ans;
            watching.insert(vec[i].second);
        }
    }
    cout << ans << "\n";
    return 0; 
}
