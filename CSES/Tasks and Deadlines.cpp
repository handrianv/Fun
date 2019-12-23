/* 
    Suppose we already have the order of task we want to solve, then total reward we get is:
    (deadline[1] - duration[1]) + (deadline[2] - duration[2] - duration[1]) +  (deadline[3] - duration[3] - duration[2] - duration[1]) + ...
    
    Which we can also write as X - Y where:
    X = sum of all deadlines
    Y = (n * duration[1]) + ((n-1) * duration[2]) + .. + (1 * duration[n])
    X is constant no matter the order we do the task. For Y, it'll be minimized by processing task from smallest duration
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> vec(n); // {duration, deadline}
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    ll currTime = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += (vec[i].second - vec[i].first - currTime);
        currTime += vec[i].first;
    }
    cout << ans << "\n";
    return 0; 
}