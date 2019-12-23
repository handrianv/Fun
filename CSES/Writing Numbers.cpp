/* 
    #1: If we can write until n, we can also write until m < n. Use binary search.
    #2: We can count how many times digit d appears from 1 to n using digit dp.
    #3: Actually we only need to count how many times "1" appears, because it'll always appear the most.

    TODO: More concise implementation
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
 
typedef long double ld;
typedef unsigned long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

ll n;
ll pow10[20];

ll ToNum(string str)
{
    ll res = 0;
    for(auto& ch : str)
    {
        res *= 10;
        res += (ch-'0');
    }
    return res;
}

ll DP(string str, int idx, int d)
{
    if(idx == str.size()) return 0;

    ll freq = 0;
    int currDigit = str[idx] - '0';
    int suffixLength = str.size()-idx-1;
    freq += (currDigit * pow10[suffixLength] * suffixLength / 10); // from digits to the right
  
    // This digit itself
    if(d < currDigit)
    {
        freq += pow10[suffixLength]; 
    }
    else if(d == currDigit)
    {
        freq += (ToNum(str.substr(idx+1)) + 1);
    }
    freq += DP(str, idx+1, d);
    return freq;
}

bool Try(string str)
{
    return DP(str, 0, 1) <= n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    pow10[0] = 1;
    for(int i = 1; i < 20; ++i) pow10[i] = pow10[i-1] * 10;
    cin >> n;
    ll left = 1, right = 1e18+5, ans = -1;
    while(left <= right)
    {
        ll mid = left + (right-left) / 2;
        if(Try(to_string(mid)))
        {
            ans = mid;
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }   
    }
    cout << ans << "\n";
    return 0; 
}