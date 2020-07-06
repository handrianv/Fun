/*
    Suppose student number i wants to be the x'th person to speak.
    Then the turn should start from student number pos = (1+ ((i-x)%n)).
    So for every student, we increment arr[pos] where pos is defined above, and take the pos such that arr[pos] is maximum.

    Visualization:
    4 1 2 3
    1 2 3 4 
    Imagine a rope connecting each number in the upper array to corresponding number in lower array.

    4 1 2 3
     / / / /
    1 2 3 4 (the 4 is connected to the upper 4 by rope of length 1, because it's circular)

    We can shift the lower array by pos, and we need to find shift that maximizes number of vertical rope.
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
#include <random>
#include <chrono>
 
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
    vector<int> cnt(n+5);
    int ans = 0, ansCnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;

        int d = i-x;
        if(d < 0) d += n;
        if(++cnt[d] > ansCnt)
        {
            ansCnt = cnt[d];
            ans = d;
        }
    }
    cout << (1+ans) << "\n";
    return 0;
}
