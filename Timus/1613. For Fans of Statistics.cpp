/*
     Store index of occurence of each number. Then do binary search.
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
    unordered_map<int, vector<int>> pos;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        pos[x].push_back(i+1);
    }

    int q;
    cin >> q;
    string ans = "";
    while(q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        auto& vec = pos[x];
        auto iter = lower_bound(vec.begin(), vec.end(), l);
        (iter != vec.end() && (*iter) <= r) ? ans += "1" : ans += "0";
    }
    cout << ans << "\n";
    return 0;
}
 
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/