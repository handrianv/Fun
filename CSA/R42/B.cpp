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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    string s, a, b;
    cin >> s >> a >> b;
    if(a.size() > b.size()) swap(a, b);

    string ans = "";
    int x = a.size(), y = b.size();
    for(int i = 0; i < s.size(); ++i)
    {
        string tempa = s.substr(i, x);
        string tempb = s.substr(i, y);
        if(tempa == a)
        {
            ans += b;
            i += (y-1);
        }
        else if(tempb == b)
        {
            ans += a;
            i += (x-1);
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans << "\n";
    return 0; 
}
