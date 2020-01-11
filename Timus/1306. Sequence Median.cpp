/* 
  To save memory:
  -. Keep only first (n / 2) smallest number. This can be done with heap by popping the largest element whenever size of heap > n/2
  -. Use vector as heap
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    int limit = ceil((double)(n+1)/2.0);
    vector<int> vec; vec.reserve(125005);
    make_heap(vec.begin(), vec.end());

    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        vec.push_back(x);
        push_heap(vec.begin(), vec.end());
        if(i > limit)
        {
            pop_heap(vec.begin(), vec.end());
            vec.pop_back();
        }
    }
    double ans;
    ans = (double)(vec[0]);
    if(n % 2 == 0)
    {
        pop_heap(vec.begin(), vec.end());
        vec.pop_back();
        ans = (ans + (double)vec[0])/2.0;
    }
    cout << fixed << setprecision(1);
    cout << ans << "\n";
    return 0; 
}