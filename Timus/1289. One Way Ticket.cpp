/*
    Important property of digital root, D(x) is:
    -. 0 if x is 0
    -. 9 if (x mod 9) == 0
    -. (x mod 9) otherwise

    So numbers with same remainder mod 9 will have the same digital root.
    There are neatly 10^n-1 numbers, so without considering 0, every remainder mod 9 appears (10^n-1 / 9) times.
    E.g. from 1 until 9999 every remainder mod 9 appears 1111 times.

    So we are looking at (111...1)^2 * 9 + 1.
    -. (111...1) ^ 2 -> each number with same remainder can be paired with any other number with same remainder.
    -. * 9 -> there are nine such remainder
    -. + 1 -> for the number 0

    The rest is noticing that the resulting number has a pattern, depending on the length of (111...1)
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
    int n;
    cin >> n;
    n /= 2;
    if(n == 1) cout << "10\n";
    else if(n == 2) cout << "1090\n";
    else
    {
        string ans = "";
        for(int i = 0; i < n-1; ++i) ans += "1";
        ans += "0";
        for(int i = 0; i < n-2; ++i) ans += "8"; 
        ans += "90";
        cout << ans << "\n";
    }
    return 0;
}
     
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/