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
#include <bitset>
 
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
 
const int MAXNUM = 1e5+5;
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;
    vector<int> freq(MAXNUM);
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++freq[x];
    }

    ll ans = 0;
    int left = 1, right = 1e5;
    while(true)
    {
        while(freq[left] == 0 && left < right) ++left;
        while(freq[right] == 0 && right > left) --right;

        if(right-left <= k)
        {
            cout << ans << "\n";
            return 0;
        }

        int minfreq = min(freq[left], freq[right]);
        ans += minfreq;
        freq[left] -= minfreq, freq[right] -= minfreq;
        freq[left+1] += minfreq, freq[right-1] += minfreq;
    }
    cout << ans << "\n";
    return 0; 
}