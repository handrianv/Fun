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
#include <bitset>
#include <random>
#include <chrono>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    string str;
    cin >> str;
    int n = str.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(30, vector<int>(30, 2e9)));

    // Base case
    for(int i = 0; i < 26; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            dp[1][i][j] = (str[0]-'a' != i) + (str[1]-'a' != j);
        }
    }

    int ans = 2e9;
    for(int i = 2; i < n; ++i)
    {
        for(int prev = 0; prev < 26; ++prev)
        {
            for(int curr = 0; curr < 26; ++curr)
            {
                if(curr == prev) continue;
                for(int pprev = 0; pprev < 26; ++pprev)
                {
                    if(pprev == prev || pprev == curr) continue;
                    dp[i][prev][curr] = min(dp[i][prev][curr], dp[i-1][pprev][prev] + (str[i]-'a' != curr));
                }
                
                if(i == n-1) ans = min(ans, dp[i][prev][curr]);
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
 
/*

*/ 