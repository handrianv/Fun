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
    int n;
    cin >> n;
    vector<pi> vec;
    vec.reserve(2*n);
    set<int> availableRooms;
    for(int i = 1; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, i}); vec.push_back({b+1, -i});
        availableRooms.insert(i);
    }

    sort(vec.begin(), vec.end());
    vector<int> roomOf(n+5);
    int sum = 0, ans = 0;

    for(auto& v : vec)
    {
        sum += (v.second > 0 ? 1 : -1);
        ans = max(ans, sum);
        if(v.second > 0)
        {
            int room = *(availableRooms.begin());
            availableRooms.erase(availableRooms.begin());
            roomOf[v.second] = room;
        }
        else
        {
            availableRooms.insert(roomOf[-v.second]);
        }
    }
    cout << ans << "\n";
    for(int i = 1; i <= n; ++i)
    {
        cout << roomOf[i];
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0; 
}