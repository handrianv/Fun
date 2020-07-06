/*
    Note that greedily matching as many people as possible is not always optimal, because of the "k" multiplier for the boys.
    Suppose we already chose k people to be matched, then we should greedily match people with highest anger to minimize sum of anger of unmatched people.
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
    int n, m;
    cin >> n >> m;
    vector<int> girls(n), boys(m);
    int sg = 0, sb = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> girls[i];
        sg += girls[i];
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> boys[i];
        sb += boys[i];
    }
    sort(girls.begin(), girls.end()); sort(boys.begin(), boys.end());

    int ans = sg, ansAll = sg; // Assume no match
    int pg = n-1, pb = m-1;
    while(pg >= 0 && pb >= 0)
    {
        ans -= girls[pg];
        ans -= (boys[pb] * (m-1-pb));
        sb -= boys[pb];
        ans += sb;
        ansAll = min(ansAll, ans);
        --pg; --pb;
    }
    cout << ansAll << "\n";
    return 0;
}
