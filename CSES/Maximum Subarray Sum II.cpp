/*

*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int len = b-a+1;
    vector<ll> vec(n+5);
    for(int i = 1; i <= n; ++i) cin >> vec[i];
    vector<ll> prefSum(n+5);
    for(int i = 1; i <= n; ++i) prefSum[i] = vec[i] + prefSum[i-1];
    // for(int i = 0; i <= n; ++i) cout << prefSum[i] << " ";
    // cout << endl;

    deque<pli> deq; // {sum, idx}
    deq.push_back({0, 0});
    ll ans = -1e16;
    for(int i = 0; i+a <= n; ++i)
    {
        if(i-deq.front().second+1 > len) deq.pop_front();
        //cout << "front " << deq.front().first << endl;
        ans = max(ans, prefSum[i+a] - deq.front().first);
        while(!deq.empty() && prefSum[i+1] <= deq.back().first)
        {
            deq.pop_back();
        }
        deq.push_back({prefSum[i+1], i+1});
    }
    cout << ans << "\n";
    return 0; 
}