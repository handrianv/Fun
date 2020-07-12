/*
    Solution #1
    -. Fix one point, fix a second point, these two point forms a line.
       Try every other point and check if it's collinear with the line. Complexity: O(N^3)

    Solution #2
    -. Fix one point. Loop through every other point. Slope between two point is (y2-y1)/(x2-x1). Equal slope means collinear.
       Count the most frequent slope. Using map, this is O(N^2 log N).
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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        map<pi, int> cnt;
        for(int j = i+1; j < n; ++j)
        {
            int dy = y[j]-y[i];
            int dx = x[j]-x[i];
            int g = __gcd(abs(dy), abs(dx));
            if(dy < 0 && dx < 0) dy *= -1, dx *= -1;
            ans = max(ans, ++cnt[{dy/g, dx/g}]);
        }
    }
    cout << (ans+1) << "\n";
    return 0;
}