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
    std::ios::sync_with_stdio(false); cin.tie(0);
    ld h; int q;
    cin >> h >> q;
    multiset<pll> nextLeaks;
    multiset<ll> currLeaks;
    bool can = false;
    for(int i = 0; i < q; ++i)
    {
        ll t, hh;
        cin >> t >> hh;
        can |= (hh == 0);
        if(t == 0 && hh < h)
        {
            currLeaks.insert(hh);
        }
        else if(t > 0 && hh < h)
        {
            nextLeaks.insert({t, hh});
        }
    }

    if(!can)
    {
        cout << "-1\n";
        return 0;
    }

    ll speed = currLeaks.size(); ld t = 0;
    while(!currLeaks.empty() || !nextLeaks.empty())
    {
        //cout << "Simulate h " << h << "\n";
        ld tNxtCurr = (currLeaks.empty()) ? 2e9 : (h - (*currLeaks.rbegin())) / speed;
        ld tNxtLeak = (nextLeaks.empty()) ? 2e9 : (ld)nextLeaks.begin()->first - t;
        
        if(tNxtCurr < tNxtLeak)
        { 
            //cout << "nextCurr with t " << tNxtCurr << "\n";
            // Before tNxtCurr second, we use current speed
            h -= (speed * tNxtCurr);
            t += tNxtCurr;
            // After tNxtCurr second, this leak disappears
            --speed;
            currLeaks.erase(--currLeaks.end());
        }
        else
        {
            //cout << "nextLeak with t " << tNxtLeak << "\n";
            // Before tNxtLeak second, we use current speed
            h -= (speed * tNxtLeak);
            t += tNxtLeak;
            // Check if height is still above the leak
            if(h > nextLeaks.begin()->second)
            {
                ++speed;
                currLeaks.insert(nextLeaks.begin()->second);
            }
            nextLeaks.erase(nextLeaks.begin());
        }
        // Fully drained, don't continue
        if(!(h > 0)) break;
        //cout << "Now t " << t << " speed " << speed << "\n";
    }
    cout << fixed << setprecision(9);
    cout << t << "\n";
    return 0;
}
 
/*
set vs multiset
cout setprecision for doubles!!
*/ 