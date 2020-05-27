/* 
    State
    dp[n][k] = answer for n horses with k partitions. 

    Transition
    Just brute force position of last partition
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
typedef pair<bool, int> pbi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int Sum(const vector<vector<ll>>& psum, int left, int right)
{
    return (psum[right][0] - psum[left-1][0]) * (psum[right][1] - psum[left-1][1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> color(n+5, vector<ll>(2)); // {length, color}
    for(int i = 1; i <= n; ++i)
    {
        int c;
        cin >> c;
        ++color[i][c];
        
        color[i][0] += color[i-1][0];
        color[i][1] += color[i-1][1];
    }

    vector<vector<ll>> dp(n+5, vector<ll>(k, 1e16));
    for(int i = 1; i <= n; ++i)
    {
        dp[i][0] = Sum(color, 1, i);
        for(int numPartition = 1; numPartition < i && numPartition < k; ++numPartition)
        {
            for(int lastPartition = i; lastPartition > numPartition; --lastPartition)
            {
                dp[i][numPartition] = min(dp[i][numPartition], dp[lastPartition-1][numPartition-1] + Sum(color, lastPartition, i));
            }
        }
    }

    cout << dp[n][k-1] << "\n";
    return 0;  
}