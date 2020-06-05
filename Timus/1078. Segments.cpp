/* 
    Sort the segments by decreasing right endpoint. Now the problem is reduced to finding LIS of left endpoints.
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

struct Interval 
{
    int left, right, idx;
    Interval(){}
    Interval(int l, int r, int idx) : left(l), right(r), idx(idx) {}
};

bool operator <(const Interval& x, const Interval& y) {
    if(x.right == y.right) return x.left < y.left;
    return x.right > y.right;
}

void Backtrack(int idx, const vector<int>& par)
{
    cout << (idx + 1);
    if(par[idx] != -1)
    {
        cout << " ";
        Backtrack(par[idx], par);
    }
    else cout << "\n";
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<Interval> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i].left >> vec[i].right;
        vec[i].idx = i;
    }

    sort(vec.begin(), vec.end());

    int last = 0;
    vector<int> dp(n), par(n, -1);
    for(int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for(int j = i-1; j >= 0; --j)
        {
            if(vec[j].left < vec[i].left && vec[j].right > vec[i].right && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                par[vec[i].idx] = vec[j].idx;
            }
        }
        if(dp[i] > dp[last]) last = i;
    }

    cout << dp[last] << "\n";
    Backtrack(vec[last].idx, par);
    return 0;
}

/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
*/