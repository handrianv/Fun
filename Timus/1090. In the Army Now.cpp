/*
    Quite trivial with order statistic. See https://codeforces.com/blog/entry/11080
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;
    int ans = -1, ansIdx = -1;
    for(int i = 1; i <= k; ++i)
    {
        ordered_set s;
        int curr = 0;
        for(int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            curr += s.size() - s.order_of_key(x);
            s.insert(x);
        }
        if(curr > ans)
        {
            ans = curr;
            ansIdx = i;
        }
    }
    cout << ansIdx << "\n";
    return 0;
}
 
/*
 
*/  