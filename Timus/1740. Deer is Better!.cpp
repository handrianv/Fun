/*
    What the problem is saying: we must cover k-kilometer in h-hours, but the speed can be variable e.g. we can burst the first k-1 km in 0,5 second and the rest 1 km in h(hour)-0.5(second)
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
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int l, k, h;
    cin >> l >> k >> h;
    cout << fixed << setprecision(9);
    int mult = l/k;
    ld ans = mult*h;
    if(l-k*mult > 0)
    {
        cout << ans+EPS << " " << ans+h-EPS << "\n";
    }
    else
    {
        cout << ans << " " << ans << "\n";
    }
    
    return 0;
}
 
/*
 
*/ 