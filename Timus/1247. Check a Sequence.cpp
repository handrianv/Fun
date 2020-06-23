/* 
    A common trick to solve subarray sum inequalities like this is to make the rhs constant. So let's rewrite the condition as:
    -. A[i] + A[i+1] + ... + A[n] - (j-i+1) <= N
    Another common trick for checking sum of subarray minus its length is to simply subtract every element by 1. Now the condition is
    -. A[i] + A[i+1] + ... + A[n] <= N
    We need this property to hold for all subarray, so we just need to check the subarray with maximum sum. Classic problem solvable with Kadane algorithm.
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
    int s, n;
    cin >> s >> n;
    vector<int> vec(s);
    for(int i = 0; i < s; ++i)
    {
        cin >> vec[i];
        --vec[i];
    }

    int bestHere = vec[0], bestAll = vec[0];
    for(int i = 1; i < s; ++i)
    {
        bestHere = max(vec[i], vec[i] + bestHere);
        bestAll = max(bestAll, bestHere);
    }
    (bestAll) <= n ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/