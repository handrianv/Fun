/* 
    The problem is asking for maximum tripartite matching which is NP-hard. Limit is small, so we can just do naive 2^k brute force.
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int k;
    cin >> k;
    vector<vector<int>> teams(k, vector<int>(3));
    map<string, int> nameIdx;

    for(int i = 0; i < k; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            string name;
            cin >> name;
            if(nameIdx.find(name) == nameIdx.end())
            {
                nameIdx[name] = nameIdx.size();
            }
            teams[i][j] = nameIdx[name];
        }
    }

    int ans = 0;
    for(int mask = 0; mask < (1<<k); ++mask)
    {
        bitset<55> has;
        int numOn = 0; bool can = true;

        for(int b = 0; b < k; ++b)
        {
            if(mask & (1<<b))
            {
                ++numOn;
                for(int j = 0; j < 3; ++j)
                {
                    if(has[teams[b][j]])
                    {
                        can = false;
                        break;
                    }
                    has[teams[b][j]] = true;
                }
                if(!can) break;
            }
        }

        if(can) ans = max(ans, numOn);
    }
    cout << ans << "\n";
    return 0;
}
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/