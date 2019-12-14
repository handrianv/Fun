/* 

*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
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
    vector<pair<pi, int>> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i].first.first >> vec[i].first.second >> vec[i].second;
    sort(vec.begin(), vec.end());
    vector<ll> dp(n+5);
    for(int i = n-1; i >= 0; --i)
    {
        int left = vec[i].first.first, right = vec[i].first.second, score = vec[i].second;
        int nxt = upper_bound(vec.begin(), vec.end(), pair<pi, int>(pi(right, 1e9+7), -1)) - vec.begin();
        dp[i] = max(dp[i+1], score + dp[nxt]);
    }
    cout << dp[0] << "\n";
    return 0; 
}
