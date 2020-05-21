/* 
    WLOG assume index of source station < destination station.
    For each ticket we should use it to get to the rightmost possible station, because for i < j, any station reachable by station[i] is also reachable by station[j]. 
    
    The rest is simple DP:
    State
    dp[n] = minimum cost if we start from n'th station.

    Transition
    For each ticket we can binary search rightmost index m reachable. Then dp[n] = dp[m] + cost of ticket.

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

int nxt(const vector<int>& dist, int curr, int l)
{
    int res = upper_bound(dist.begin(), dist.end(), dist[curr] + l) - dist.begin() - 1;
    return res;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int l1, l2, l3, c1, c2, c3, n, source, dest;
    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3 >> n >> source >> dest;

    vector<int> dist(n);
    for(int i = 1; i < n; ++i)
    {
        cin >> dist[i];
    }

    if(source > dest) swap(source, dest);
    --source; --dest;
    vector<int> dp(n+5, 1e9+5); dp[dest] = 0;

    for(int i = dest-1; i >= source; --i)
    {
        int ticket1 = dp[min(dest, nxt(dist, i, l1))] + c1;
        int ticket2 = dp[min(dest, nxt(dist, i, l2))] + c2;
        int ticket3 = dp[min(dest, nxt(dist, i, l3))] + c3;
        dp[i] = min({ticket1, ticket2, ticket3});
    } 

    cout << dp[source] << "\n";
    return 0;  
}