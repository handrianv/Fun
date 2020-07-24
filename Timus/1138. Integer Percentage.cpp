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
    int n, s;
    cin >> n >> s;
    vector<int> dp(n+5);
    dp[s] = 1;
    for(int i = s; i < n; ++i)
    {
        if(dp[i] == 0) continue;
        for(int p = 1; p <= 100; ++p)
        {
            if((i*p) % 100 == 0) // Check if p percent of this number is an integer
            {
                int increase = i*p/100;
                if(i+increase <= n) dp[i+increase] = max(dp[i+increase], dp[i] + 1);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
/*

*/