/*
    Let's first think of a simple brute force solution. If we fix the width, the height will also be fixed, and we can count how many points are inside this rectangle.
    But how to brute force the width, since it can be any real number (not necessarily integer)?

    It's often the case that in problems like these, where we have points in 2d plane and are trying to find where to place some optimal vertical line (the width), that the optimal line will always intersect a point.
    Turns out it's also the case in this problem. Proving it is quite straightforward. If the width does not intersect any point, we can move it to the nearest point to the left without changing the height. The resulting rectangle will still contain the 
    same number of points but requiring smaller area.

    So now we can do a simple sweep line. Sort points by x-coord, and iterate from left to right. Imagine the width is equal to the x-coord of current point, then we know height (which can be floored to the nearest integer, by the same argument above).
    We need to count how many points have y-coord below this height. A classic problem solvable with fenwick tree.

    But we can make an observation to avoid using fenwick. As we sweep to the right, the height will always decrease. So we can maintain the y-coord of points using set, and as we sweep, remove from the set all points with y-coord > current height.
    Each point is inserted to the set once, removed once. We also do sorting in the beginning. So complexity is O(N log N)
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
#define CeilDiv(a, b) ((a+b-1)/b)
 
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
    int n, a;
    cin >> n >> a;
    vector<pi> vec(n);
    for(auto& v : vec)
    {
        cin >> v.first >> v.second;
    }
    sort(vec.begin(), vec.end());   

    multiset<int> s;
    int ans = 0;
    for(auto& v : vec)
    {
        int w = v.first;
        int h = a/w;
        s.insert(v.second);
        while(!s.empty() && (*s.rbegin()) > h) s.erase(--s.end());
        ans = max(ans, (int)s.size());
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 