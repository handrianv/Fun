/*
    Given N lattice points, compute average of sum of all pair manhattan distance.
    As usual with manhattan distance problem, we can solve for X and Y coordinate separately and sum them up in the end.

    Suppose we are working on X coordinates, and the points are 0-indexed following the input order.
    Then the sum of X-distance from point[i] to all point[j < i] is:
    -. (p[i]-p[0] + p[i]-p[1] + .... + p[i]-p[i-1]) -> i * p[i] - (sum of p[j], 0 <= j < i)
    So we can do it in O(N) by maintaining prefix sums of j.

    Do this for Y-coordinate as well, sum them up, and divide by number of pairs to get the average.
    Note that since we count each pair only once, the number of pair is C(N, 2)
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
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll SumDist(const vector<ll>& vec)
{
    ll sum = 0, pref = vec[0];
    for(int i = 1; i < (int)vec.size(); ++i)
    {
        sum += (vec[i] * i - pref);
        pref += vec[i];
    }
    return sum;
}

ll Prog(ll n)
{
    return (n%2 == 0) ? n/2*(n-1) : (n-1)/2*n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = (SumDist(x) + SumDist(y)) / Prog(n);
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 