/* 
    Since the given arrays are already sorted, we can do it in O(N) time and O(1) space using two pointers
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];

    int m;
    cin >> m;
    vector<int> vec2(m);
    for(int i = 0; i < m; ++i) cin >> vec2[i];

    int ptr2 = 0, target = 1e4;
    bool can = false;
    for(int i = 0; i < n; ++i)
    {
        while(ptr2 < m && vec[i] + vec2[ptr2] > target) ++ptr2;
        if(ptr2 < m && vec[i] + vec2[ptr2] == target)
        {
            can = true;
            break;
        }
    }

    (can) ? cout << "YES\n" : cout << "NO\n";
    return 0;  
}