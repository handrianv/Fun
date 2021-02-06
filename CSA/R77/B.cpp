/*
    Area of a rhombus with diagonal D1 and D2 is (D1*D2) / 2. So we need to maximize (D1*D2).
    This is maximized when D1 == D2. It should be pretty intuitive once you try some numbers. E.g. 3*7 < 4*6 < 5*5.

    Proof
    For any two real numbers a < b, we can pick some constant c <= floor(b-a / 2), and the following inequality holds:
    (a+c) * (b-c) >= ab
    To prove it, we simply expand the products:
    ab - ac + bc - c^2 >= ab
    (b-a)c - c^2 >= 0
    (b-a) >= c
    And the last line is true because we have picked c <= floor(b-a / 2)
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
    ll d1, d2, k;
    cin >> d1 >> d2 >> k;
    if(d1 > d2) swap(d1, d2);
    ll diff = min(d2-d1, k);
    d1 += diff; k -= diff;

    double area = ((k%2 != 0) + (k/2) + d1) * ((k/2) + d2);
    cout << fixed << setprecision(9);
    cout << (area/2) << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
cout << setprecision for doubles!! Costed me half a day of life!!
*/  