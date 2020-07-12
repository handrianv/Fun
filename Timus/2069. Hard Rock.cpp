/*
    Since we want to minimize the value of the answer, intuitively we should use as little road / segment as possible.
    Because walking through more segment than necessary can only worsen the answer (or maybe doesn't change it), but it can never improve it.
    I.e. adding a new number to a set cannot increase the minimum value of the set.
    
    We should start our move with either the first vertical / horizontal segment, and ends with the last vertical / horizontal segment.
    So we have 4 cases, and for each of them the shortest path is:
    1. First vertical segment -> last horizontal segment.
    2. First vertical segment -> best horizontal segment* -> last vertical segment.
    3. First horizontal segment -> last vertical segment.
    4. First horizontal segment -> best vertical segment* -> last horizontal segment.
    *here the best segment does not include the first and last segment
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
    int n, m;
    cin >> n >> m;
    vector<int> v(n), h(m);
    int bestV = 0, bestH = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        if(i > 0 && i+1 < n) bestV = max(bestV, v[i]);
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> h[i];
        if(i > 0 && i+1 < m) bestH = max(bestH, h[i]);
    }
    
    int ansV = max(min(h[0], v[n-1]), min({v[0], bestH, v[n-1]})); // Ends with last vertical
    int ansH = max(min(v[0], h[m-1]), min({h[0], bestV, h[m-1]})); // Ends with last horizontal
    cout << max(ansV, ansH) << "\n";
    return 0;
}