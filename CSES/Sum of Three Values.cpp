/* 
    Method #1:
    How to find two positions that sums to x in unsorted array? 
    We can keep occurence of each number in map, and then loop through every element arr[i] and check existence of arr[x-i].
    For three positions, fix leftmost endpoint of the answer, we can run above procedure n times for each left endpoint.
    Complexity: O(n^2) with high constant factor due to map

    Method #2:
    How to find two positions that sums to x in sorted array? 
    We can keep two pointer (left, right) that starts from beginning and end of array respectively.
    Then we can either increment left or decrement right depending on how arr[left]+arr[right] compares to x.
    For three positions, fix leftmost endpoint of the answer, we can run above procedure n times for each left endpoint.
    Complexity: O(n^2) with better constant factor than method #1
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int n, x;
vector<pi> vec;

pi ForTwoPositions(int left, int target)
{
    int right = n-1;
    while(left < right)
    {
        int s = vec[left].first + vec[right].first;
        if(s == target) return {vec[left].second+1, vec[right].second+1};
        else if(s > target) --right;
        else ++left;
    }
    return {-1, -1};
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> x;
    vec = vector<pi>(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i].first;
        vec[i].second = i;
    } 
    sort(vec.begin(), vec.end());

    for(int left = 0; left < n-2; ++left)
    {
        pi temp = ForTwoPositions(left+1, x-vec[left].first);
        if(temp.first != -1)
        {
            vector<int> ans = {vec[left].second+1, temp.first, temp.second};
            sort(ans.begin(), ans.end());
            cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0; 
}