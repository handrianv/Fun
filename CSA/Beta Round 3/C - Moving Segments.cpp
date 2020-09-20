/*
    Observation #1
    If the vertical line does not intersect a segment endpoint, we can make it more optimal (or at least not worse) by moving it to an endpoint.
    Consider the side (to the left/right) of the vertical line that has more segment, we can move the vertical line to that side until we reach the nearest endpoint. Since one side has more segment, moving it to that 
    side will decrease the sum of distance more than it increase.
    With this we can do sweep line, for each endpoint calculate the cost of moving all other segment to this point. This is enough to get accepted.

    Observation #2
    We can simplify the solution by noting that this problem is in fact very similar to the classic problem of "pick a point that minimize sum of distance from all other points", in which the answer is just the median.
    The only difference is this problem is about segments instead of points, but turns out that the optimal vertical line is still the median* of all points!

    Proof is very similar to the classic problem: 
    -. If the optimal vertical line does not intersect any segments, then there must be equal number of segments to the left & right of this line,
    or else we can move the line to the side that has more segments and it'd be more optimal. Since there are equal number of segments to the left & right, it means there are also equal number
    of points to the left & right. Then this line must be the median of all points.

    -. If the line does intersect some segments, then each segment that intersects it will contribute 1 point to the left side and 1 point to the right side, so the number of points to 
    the left & right is still equal. The rest of the segment does not intersect this line, then we use the same argument as case 1 to prove that this line must be the median of all points.

    *Note: since we are guaranteed to have even number of points (each segment contribute 2 endpoint), we can pick either points[floor(n/2)] or points[ceil(n/2)] as median.
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
#include <random>
#include <chrono>
 
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
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> points; points.reserve(2*n);
    vector<pi> segments(n);
    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        segments[i] = {l, r};
        points.push_back(l); points.push_back(r);
    }

    sort(points.begin(), points.end());
    int target = points[points.size()/2];

    ll ans = 0;
    for(auto& v : segments)
    {
        if(v.second < target) ans += (target-v.second);
        else if(v.first > target) ans += (v.first-target);
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 