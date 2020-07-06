/*
    m people need d1 days, then 1 people need d1*m days.
    To finish in exactly d2 days, we need n = (d1*m)/d2 people each day.
    To get rid of floating point, we can distribute ceil(n) people to (d1*m) % d2 days, and floor(n) people to the rest.
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
    int m, d1, d2;
    cin >> m >> d1 >> d2;
    m *= d1;
    int c = (m+d2-1)/d2, f = m/d2, r = m % d2;
    for(int i = 0; i < r; ++i)
    {
        cout << c << " ";
    }
    for(int i = 0; i < d2-r; ++i)
    {
        cout << f;
        (i+1 == d2-r) ? cout << "\n" : cout << " ";
    }
    return 0;
}
