/*
 
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
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    while(!str.empty() && str.back() == '0') str.pop_back();
    reverse(str.begin(), str.end());

    int n = str.size();
    if(n == 0)
    {
        cout << "0\n";
        return 0;
    }
    
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[n-1][0] = (str[n-1] == '1'), dp[n-1][1] = dp[n-1][0] ^ 1;
    for(int i = n-2; i >= 0; --i)
    {
        dp[i][0] = (str[i] == '0') ? dp[i+1][0] : dp[i+1][1] + 1 + ( (1LL << (n-i-1)) - 1);
        dp[i][1] = (str[i] == '1') ? dp[i+1][0] : dp[i+1][1] + 1 + ( (1LL << (n-i-1)) - 1);
    }
    cout << dp[0][0] << "\n";
    return 0;
}
 
/*
 
*/  