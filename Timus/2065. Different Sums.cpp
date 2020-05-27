/* 
    Since negative values are allowed, we can fill the array with the following pattern:
    [1, -1, 2, -2, 3, -3, ...., 0, 0, 0, ...., 0]

    It's not difficult to prove that this is optimal. Let X = number of distinct subarray sums, and S(L, R) sum of a subarray:
    -. Since there are at least k unique elements, X >= k.
    -. From subarray of length 1, we will get k distinct sums. Each sum will be in range [-floor(k/2), floor(k/2)]
    -. Now consider any subarray of length > 1. Then 0 <= S(L, R) <= floor(k/2).
    So any S(L, R), R-L > 1 will have sum equal to one of subarray with length 1. Then X = k, which is optimal.
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;

    int curr = 1;
    for(int i = 0; i < k-1; ++i)
    {
        cout << curr;
        (i+1 == n) ? cout << "\n" : cout << " ";
        curr *= -1;
        if(curr > 0) ++curr;
    }

    for(int i = k-1; i < n; ++i)
    {
        cout << "0";
        (i+1 == n) ? cout << "\n" : cout << " ";
    }
    return 0;  
}