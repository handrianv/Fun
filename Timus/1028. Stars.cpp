/* 
    Do sweep line by increasing y. For every point, we need to query how many previous points p have x <= current x.
    We can do this in O(log N) per query using either fenwick tree or order statistic set (https://codeforces.com/blog/entry/11080)
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;

    ordered_set s;
    vector<int> ans(n);
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        ++ans[s.order_of_key({x, i})];
        s.insert({x, i});
    }

    for(int i = 0; i < n; ++i)
    {
        cout << ans[i] << "\n";
    }
    return 0;  
}