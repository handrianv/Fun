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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 2e5+5;
int n, k;
int arr[MAXN];

bool Try(ll limit)
{
    ll need = 0, sum = 0;
    for(auto& num : arr)
    {
        if(num > limit) return false;
        sum += num;
        if(sum > limit)
        {
            sum = num;
            ++need;
        }
    }
    return (need+1 <= k);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    ll left = 0, right = 2e14+5, ans = 0;
    while(left <= right)
    {
        ll mid = left + (right-left) / 2;
        if(Try(mid))
        {
            right = mid-1;
            ans = mid;
        }
        else 
            left = mid+1;
    }
    cout << ans << "\n";
    return 0; 
}