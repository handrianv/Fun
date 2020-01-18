/* 

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
    int n, k;
    cin >> n >> k;
    vector<int> vec(n+5, 1e9+7);
    for(int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        vec[x] = 1;
    }
    for(int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        vec[x] = 2;
    }

    int cnt = 0;
    vec[0] = vec[n];
    for(int i = 0; i <= n; ++i)
    {
        if(vec[i] + vec[i+1] == 3)
        {
            vec[i+1] = 3;
            ++cnt;
            if(i == 0) vec[n] = 3;
        }
    }
    cout << (cnt + (k-cnt) * 2) << "\n";
    return 0; 
}