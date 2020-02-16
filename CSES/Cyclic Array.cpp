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
    int n; ll k;
    cin >> n >> k;
    vector<ll> vec(2*n);
    for(int i = 0; i < n; ++i)
    {
      cin >> vec[i];
      vec[i+n] = vec[i];
    }
 
    vector<ll> psum(2*n); psum[0] = vec[0];
    for(int i = 1; i < 2*n; ++i)
    {
      psum[i] = vec[i] + psum[i-1];
    }
 
    vector<int> need(2*n);
    for(int i = 2*n-1; i >= 0; --i)
    {
      auto iter = upper_bound(psum.begin()+i, psum.end(), psum[i]-vec[i]+k);
      if(iter == psum.end()) need[i] = 1;
      else need[i] = need[iter-psum.begin()] + 1;
      //cout << "need " << i << " " << need[i] << endl;
    }
 
    int ans = 2*n;
    for(int i = 0; i < n; ++i)
    {
      ans = min(ans, need[i] - need[i+n-1] + 1);
    }
    cout << ans << "\n";
    return 0; 
}