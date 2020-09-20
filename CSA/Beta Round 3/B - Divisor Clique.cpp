/*
    The crucial observation is if we have three numbers a < b < c, then if we know a|b and b|c, by transitivity a|c.
    What this means is that if we already have a sorted valid sequence, and we want to add a new largest element to this sequence, we only need to check that this new number
    is divisible by the currently largest number in the sequence. If it is, then this new number must also be divisible by all other number in the sequence.

    E.g. currently our sequence is {2, 6, 18}
    If we want to check if a new number X can be part of the sequence, we just check if 18|X. If it is, then we know 2 & 6 also divides X.

    With this observation, we can sort the array and pick the longest valid sequence. This can be done using dp with transition very similar to LIS.
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
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto& v : vec)
    {
        cin >> v;
    }
    sort(vec.begin(), vec.end());
    
    vector<int> dp(n); int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for(int j = i-1; j >= 0; --j)
        {
            if(vec[i] % vec[j] == 0)
            {
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 