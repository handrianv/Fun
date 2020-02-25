/*

*/
 
#include <iostream>
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
#include <cmath>
#include <cstring>
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
    int n, x;
    cin >> n >> x;
    vector<int> prices(n+5), values(n+5);
    for(int i = 0; i < n; ++i) cin >> prices[i];
    for(int i = 0; i < n; ++i) cin >> values[i];

    vector<int> dp(x+5);
    for(int i = 0; i < n; ++i)
    {
        for(int j = x; j >= prices[i]; --j)
        {
            dp[j] = max(dp[j], dp[j-prices[i]] + values[i]);
        }
    }
    cout << dp[x] << "\n";
    return 0; 
}