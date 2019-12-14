/* 

*/

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
    vector<int> cnt(30);
    for(auto& ch : str) ++cnt[ch-'A'];
    string res, mid;
    for(int i = 0; i < 26; ++i)
    {
        int temp = cnt[i] / 2;
        while(temp)
        {
            res += (i+'A');
            --temp;
        }
        if(cnt[i] % 2 != 0) mid += (i+'A');
    }
    if(mid.size() > 1) cout << "NO SOLUTION\n";
    else
    {
        cout << res << mid;
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
    return 0; 
}
