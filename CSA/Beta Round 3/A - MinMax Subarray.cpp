/* 
    For each index i, if it's the minimum element then the shortest subarray to the left is with the rightmost index <= i of maximum element.
    Similarly if index i is the maximum element.
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
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n);

    int mn = 1e9+5, mx = -1;
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        mn = min(mn, vec[i]);
        mx = max(mx, vec[i]);
    }

    int ans = n;
    int lastMn = -1, lastMx = -1;
    for(int i = 0; i < n; ++i)
    {
        if(vec[i] == mn) lastMn = i;
        if(vec[i] == mx) lastMx = i;
        if(lastMn != -1 && lastMx != -1) ans = min(ans, abs(lastMx-lastMn) + 1);
    }

    cout << ans << "\n";
    return 0;  
}