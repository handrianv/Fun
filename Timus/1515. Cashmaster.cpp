/*
    Suppose we can currently make every number from 1...n-1. So smallest number we cannnot make is n.
    Then a new number x comes in. If:
    -. x > n, then the answer is n, because every next number is also larger than n (remember that the input is given in sorted order).
    -. x <= n, then we can now make every number from n until n-1+x as well. To do so, let n <= y < n+x be the number we want to make.
       Then just take x and create (y-x) with the remaining coin. Since y-x <= n-1 and we know we can make every number from 1..n-1, this must be possible.
       So now the smallest number we can't make is n+x.
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
    vector<int> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    int ans = 1;
    for(auto& num : vec)
    {
        if(num > ans) break;
        ans += num;
    }
    cout << ans << "\n";
    return 0;
}
/*

*/