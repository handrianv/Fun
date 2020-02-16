/* 
    Algorithm runs in O(N). 
    The observation is that a position j will be inspected & passed by the second loop at most once.
    *passed here means that vec[j] >= vec[i] is true.

    Assume that in the i'th iteration, position j is passed by the second loop.
    Then vec[i] < vec[j] and ans[i] <= ans[j].
    Now in the k > i 'th iteration, it will try position i before j, and if vec[i] > vec[k], then it will go to ans[i] <= ans[j], skipping checking vec[j].
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n+5);
    for(int i = 1; i <= n; ++i) cin >> vec[i];

    vector<int> ans(n+5);
    for(int i = 1; i <= n; ++i)
    {
        int j = i-1;
        while(vec[j] >= vec[i]) j = ans[j];
        ans[i] = j;
    }

    for(int i = 1; i <= n; ++i)
    {
        cout << ans[i];
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0; 
}