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
    int n, m;
    cin >> n >> m;
    vector<pll> cats(n), dogs(m);
    for(auto& v : cats)
    {
        cin >> v.first >> v.second;
    }
    for(auto& v : dogs)
    {
        cin >> v.first >> v.second;
    }

    vector<int> cnt(n);
    for(int i = 0; i < m; ++i)
    {
        ll minDist = 1e18, idx = -1;
        for(int j = 0; j < n; ++j)
        {
            ll dx = abs(dogs[i].first - cats[j].first);
            ll dy = abs(dogs[i].second - cats[j].second);
            ll dist = dx*dx + dy*dy;
            if(dist < minDist)
            {
                minDist = dist;
                idx = j;
            }
        }
        ++cnt[idx];
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans += (cnt[i] == 1);
    }
    cout << ans << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
cout << setprecision for doubles!! Costed me half a day of life!!
*/  