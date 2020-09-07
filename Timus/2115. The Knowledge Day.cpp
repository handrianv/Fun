/*
    Just implementation.
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
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;

pi Check(const vector<int>& vec, const vector<int>& sorted)
{
    pi ans(0, 0); int cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(vec[i] != sorted[i])
        {
            ++cnt;
            (ans.first == 0) ? ans.first = (i+1) : ans.second = (i+1);
        }
    }
    if(cnt > 2) ans = {-1, -1};
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    vector<int> vec(n);
    for(auto& v : vec)
    {
        cin >> v;
    }
    vector<int> sorted = vec;
    sort(sorted.begin(), sorted.end());
    pi ans1 = Check(vec, sorted);
    reverse(sorted.begin(), sorted.end());
    pi ans2 = Check(vec, sorted);

    if(ans1.first == 0 || ans2.first == 0)
    {
        cout << "Nothing to do here\n";
    }
    else if(ans1.first == -1 && ans2.first == -1)
    {
        cout << "No hope\n";
    }
    else
    {
        pi ans = (ans1.first != -1) ? ans1 : ans2;
        cout << "Yes\n" << ans.first << " " << ans.second << "\n";
    }
    
    return 0;
}
 
/*
 
*/  