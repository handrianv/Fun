/* 
    WLOG i < j.

    First way:
    We can derive formula such that Fj = a*Fi + b*F(i+1), where a, b is some coefficient that can be computed
    in a similar fashion to fibonacci. We can find F(i+1) this way, and then compute Fn.
    However, a & b can be extremely large, so this solution must be implemented with big integer.

    Second way:
    We can binary search for F(i+1). This cleary works since increasing / decreasing F(i+1) will correspondingly
    increase / decrease every next fibonacci number.
    Note the constraint -2e9 <= Fk <= 2e9 allows us to break early if when computing any Fk we got out of range. With this we can avoid overflow.
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXFIB = 2e9;
int i, j, n;
ll fi, fj;

int Try(ll nxt)
{
    ll curr = nxt, prev = fi;
    for(int k = i+2; k <= j; ++k)
    {
        ll temp = curr + prev;
        prev = curr;
        curr = temp;
        if(curr > MAXFIB) return 1;
        if(curr < -MAXFIB) return -1;
    }
    if(curr == fj) return 0;
    else if(curr > fj) return 1;
    else return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> i >> fi >> j >> fj >> n;
    if(i > j)
    {
        swap(i, j);
        swap(fi, fj);
    }

    if(n == i)
    {
        cout << fi << "\n";
        return 0;
    }

    ll nxt = 0;
    ll left = -MAXFIB, right = MAXFIB;
    while(left <= right)
    {
        ll mid = left + (right-left) / 2;
        ll res = Try(mid);

        if(res == 0)
        {
            nxt = mid;
            break;
        }
        else if(res > 0)
        {
            right = mid-1;
        }
        else
        {
            left = mid + 1;
        }
    }

    ll prev = fi, curr = nxt; 
    int mult = 1;
    if(n < i) 
    {
        swap(prev, curr);
        mult = -1;
    }

    int r = (n > i) ? n-i-1 : i-n;
    for(int k = 0; k < r; ++k)
    {
        ll temp = prev + curr * mult;
        prev = curr;
        curr = temp;
    }
    cout << curr << "\n";
    return 0;
}

/*

*/