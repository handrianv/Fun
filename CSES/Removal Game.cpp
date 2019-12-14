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

const int MAXN = 5005;
int arr[MAXN];
ll prefSum[MAXN];
ll dp[MAXN][MAXN];
int n;

inline ll Sum(int left, int right)
{
    return (prefSum[right] - prefSum[left-1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= n; ++i) prefSum[i] = arr[i] + prefSum[i-1];

    for(int len = 1; len <= n; ++len)
    {
        for(int left = 1; left+len-1 <= n; ++left)
        {
            int right = left+len-1;
            ll takeLeft = arr[left] + Sum(left+1, right) - dp[left+1][right];
            ll takeRight = arr[right] + Sum(left, right-1) - dp[left][right-1];
            dp[left][right] = max(takeLeft, takeRight);
        }
    }
    cout << dp[1][n] << "\n";
    return 0; 
}
