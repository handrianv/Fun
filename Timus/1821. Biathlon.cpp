/*
    For each contestant we can keep two values: the exact time she finished (the one given in the input), and the time she finished plus the described 30 second intervals.
    Sort by the first value, and a contestant is first place if she has the smallest second value in the prefix.
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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<tuple<pid, pid, string>> vec(n); // {finish time, real finish time, name}

    int extra = 0;
    for(auto& v : vec)
    {
        cin >> get<2>(v);
        string t;
        cin >> t;

        pid finishTime = get<0>(v);
        finishTime.first = stoi(t.substr(0, 2));
        finishTime.second = stod(t.substr(3));
        get<0>(v) = finishTime;

        pid realTime = get<1>(v);
        int extraMin = (finishTime.second + extra) / 60;
        realTime.first = finishTime.first + extraMin;
        realTime.second = finishTime.second + (30 * (extra % 60 != 0));
        if(realTime.second >= 60) realTime.second -= 60;
        get<1>(v) = realTime;

        extra += 30;
    }

    sort(vec.begin(), vec.end());
    set<string> ans;

    pid mx(1e9, 1e9);
    for(auto& v : vec)
    {
        if(get<1>(v) < mx)
        {
            ans.insert(get<2>(v));
            mx = get<1>(v);
        }
    }

    cout << ans.size() << "\n";
    for(auto& v : ans)
    {
        cout << v << "\n";
    }
    return 0;
}
 
/*
 
*/  