/* 
    By lagrange's four square theorem, answer is at most 4.
    We can brute force the first 3 numbers in O(sqrt(N)^3). If answer is not found then it is 4. 

    Alternatively, we can also do simple DP with same complexity.
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

const int MAXN = 60005;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;

    for(int i = 0; i*i <= MAXN; ++i)
    {
        for(int j = 0; j*j <= MAXN; ++j)
        {
            for(int k = 0; k*k <= MAXN; ++k)
            {
                if(i*i + j*j + k*k == n)
                {
                    cout << ((i>0) + (j>0) + (k>0)) << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "4\n";
    return 0;  

    // DP
    // vector<int> dp(MAXN, 1e9);
    // dp[0] = 0;

    // for(int i = 1; i <= n; ++i)
    // {
    //     for(int j = 1; j*j <= i; ++j)
    //     {
    //         dp[i] = min(dp[i], dp[i-j*j] + 1);
    //     }
    // }

    // cout << dp[n] << "\n";
}

/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
*/
