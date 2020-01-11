/* 
  A number in base k is divisible by (k-1) only if its sum of digits is divisible by (k-1)

  Proof:
  Let the number be d0*(k^0) + d1*(k^1) + ... + dn*(k^n), where di is the i'th digit.
  k^n == 1 mod (k-1)
  So we want (d0 + d1 + .. + dn) == 0 mod (k-1)
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
    string str;
    cin >> str;
    int sum = 0, maxDigit = 0;
    for(auto& ch : str)
    {
      int num = (isdigit(ch)) ? (ch-'0') : (ch-'A'+10);
      sum += num;
      maxDigit = max(maxDigit, num);
    }
    
    // Base must be at least largest digit + 1
    for(int i = max(1, maxDigit); i < 36; ++i)
    {
      if(sum % i == 0)
      {
        cout << (i+1) << "\n";
        return 0;
      } 
    }
    cout << "No solution.\n";
    return 0; 
}