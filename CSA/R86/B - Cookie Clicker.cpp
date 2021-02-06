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
#include <random>
#include <chrono>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT 
    int n, c, s;
    cin >> n >> c >> s;
    vector<pi> factories(n); // {cost, extra}
    for(int i = 0; i < n; ++i)
    {
        cin >> factories[i].first >> factories[i].second;
    }
    
    int ans = 2e9;
    for(int mask = 0; mask < (1<<n); ++mask)
    {
        vector<int> idxToBuy;
        for(int b = 0; b < n; ++b)
        {
            if(mask & (1<<b))
            {
                idxToBuy.push_back(b);
            }
        }

        do {
            int curr = 0, t = 0, currS = s;
            bool hasFinished = false;
            for(auto& idx : idxToBuy) 
            {
                int need = max(0, factories[idx].first - curr);
                int tNeed = CeilDiv(need, currS);

                // Finish before buying next factory
                if(curr + tNeed*currS >= c)
                {
                    hasFinished = true;
                    t += (CeilDiv(c-curr, currS));
                    break;
                }
                t += tNeed;
                curr += (tNeed * currS);
                curr -= factories[idx].first;
                currS += factories[idx].second;
            }
            if(!hasFinished) t += (CeilDiv(c-curr, currS));
            ans = min(ans, t);
        }while(next_permutation(idxToBuy.begin(), idxToBuy.end()));
    }
    cout << ans << "\n";
    return 0;
}
 
/*

*/ 