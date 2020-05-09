/* 
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
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;

    int firstNonZero = 1e9;
    int currxor = 0, ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        currxor ^= x;
        if(currxor > 0) ans = i+1; else ans = max(ans, i-firstNonZero);
        if(currxor > 0 && firstNonZero == 1e9) firstNonZero = i;
    }
    cout << ans << "\n";
    return 0; 
}