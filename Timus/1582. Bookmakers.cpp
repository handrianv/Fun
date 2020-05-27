/* 
    If we distribute the money as m1, m2, and m3 then to maximize the minimum value we want to satisfy:
    -. k1*m1 = k2*m2 = k3*m3
    -. m1 + m2 + m3 = 1000
    Solve for any one of the variable and we can just print ki * mi since they're all equal.

    Useless personal note (not the equation used in code, but it'd work as well)
    (1)
    x1 + x2 + x3 = 1000
    k1x1 - k2x2 = 0 --> k1 * row1 - row2
    k2x2 - k3x3 = 0

    (2)
    x1 + x2 + x3 = 1000
    (k1+k2)x2 + k1x3 = 1000*k1
    k2x2 - k3x3 = 0 --> k2 * row2 - (k1+k2) row 3

    (3)
    x1 + x2 + x3 = 1000
    (k1+k2)x2 + k1x3 = 1000*k1
    k1k2x3 + k3(k1+k2)x3 = 1000*k1*k2
    
    (4)
    Solve for x3.
    (k1k2 + k1k3 + k2k3)x3 = 1000*k1*k2
    x3 = 1000*k1*k2 / (k1k2 + k1k3 + k2k3)
    k3x3 = k1x1 = k2x2 = 1000*k1*k2*k3 / (k1k2 + k1k3 + k2k3)
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
typedef pair<bool, int> pbi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    double k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    double a = 1000.00 / (1.0 + (k1 / k2) + (k1 / k3));
    cout << round(k1 * a) << "\n";
    return 0;  
}