/*
    For two consecutive subarray, a partition is valid if max value of the left subarray <= min value of the right subarray.
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
    vector<int> mn(n); mn[n-1] = vec[n-1];
    for(int i = n-2; i >= 0; --i)
    {
        mn[i] = min(vec[i], mn[i+1]);
    }

    int ans = 1, mx = 0;
    for(int i = 0; i < n-1; ++i)
    {
        mx = max(mx, vec[i]);
        if(mx <= mn[i+1])
        {
            ++ans;
            mx = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}

/*

*/