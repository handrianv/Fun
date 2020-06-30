/*
    We can pick:
    A = N^2 + N
    B = N^2 + 2*N
    C = N^2

    A^2 + B^2 will be divisible by C, because each term in the summation is a multiple of N^2
    Such A and B always exist within the given constraint, because (N+1)^2 = (N^2 + 2n + 2) > B > A

    How to come up with such solution?
    Perhaps the magical part is choosing C = N^2, which is more of an intuition.
    After choosing such a C, everything else follows naturally. We want A and B to be > N^2, and contain only N as term
    Since the range of number we can choose is limited, intuitively we should pick two smallest such number, which is +N and +2*N
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
    ll n;
    cin >> n;
    ll sq = n*n;
    cout << (sq+n) << " " << (sq+2*n) << " " << sq << "\n";
    return 0;
}


/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/