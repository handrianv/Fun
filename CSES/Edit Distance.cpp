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
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    a.insert(0, "x"); b.insert(0, "x");

    vector<int> dp(b.size()+5);
    for(int i = 1; i < b.size(); ++i) dp[i] = i;

    for(int i = 1; i < a.size(); ++i)
    {
        vector<int> cpy = dp;
        dp[0] = i;
        for(int j = 1; j < b.size(); ++j)
        {
            dp[j] = min(dp[j-1]+1, cpy[j]+1);
            dp[j] = min(dp[j], cpy[j-1] + (a[i] != b[j]));
        }
    }
    cout << dp[b.size()-1] << "\n";
    return 0; 
}