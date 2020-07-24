/*
    If we produce x quantity of horns and y quantity of hoofs, our total profit is:
    Ax + By - x^2 - y^2
    Subject to x + y <= k.

    If we increase quantity of horn by one, we get extra profit with (possibly negative) value of:
    A - ((x+1)^2 - x^2). Similarly for B.
    Now it's clear that at each step we can just increase whichever one gives more profit until either x + y = k or both results in negative profit.
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
    double a, b; int k;
    cin >> a >> b >> k;

    int cntA = 0, cntB = 0; double ans = 0;
    while(cntA + cntB < k)
    {
        double profitA = a - ((cntA + 1) * (cntA + 1) - (cntA * cntA));
        double profitB = b - ((cntB + 1) * (cntB + 1) - (cntB * cntB));
        if(!(profitA > 0 || profitB > 0)) break;
        if(profitA > profitB)
        {
            ans += profitA;
            ++cntA;
        }
        else
        {
            ans += profitB;
            ++cntB;
        }        
    }
    cout << fixed << setprecision(9);
    cout << ans << "\n" << cntA << " " << cntB << "\n";
    return 0;
}