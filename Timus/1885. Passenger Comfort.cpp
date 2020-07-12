/*
    To get minimum time, we want to move at speed v for k seconds until the rest of the distance can be covered with speed x for (t-k) seconds.
    h-k*v = (t-k)*x
    h-k*v = t*x - k*x
    k(x-v) = t*x-h
    k = (t*x-h)/(x-v)
    
    To get max time, we want to get minimum speed > x that can still cover the distance in time t.
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
    double h, t, v, x;
    cin >> h >> t >> v >> x;
    double ans1 = max(0.0, (x*t-h) / (x-v));

    double left = x, right = v;
    for(int i = 0; i < 200; ++i)
    {
        double mid = left + (right-left) / 2;
        if(mid * t < h)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    double ans2 = h / ((left + right) / 2);
    cout << fixed << setprecision(9);
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
