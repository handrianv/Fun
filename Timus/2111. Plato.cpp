/* 
    We can actually visit cities in any order. To prove this, consider weight W and 2 distances Di, Dj:

    If we do Di before Dj, total cost is:
    C1 = Di * (2W - Di) + Dj * (2*(W-Di) - Dj)

    If we do Dj before Di, total cost is
    C2 = Dj * (2W - Dj) + Di * (2*(W-Dj) - Di)

    C1 - C2 = 0, which implies that no matter which cities we visit first, the end cost is the same.
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
    int n;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    ll sum = 0, ans = 0;
    for(auto& v : vec)
    {
        ans += (v * (2*sum - v));
        sum -= v;
    }
    cout << abs(ans) << "\n";
    return 0;  
}