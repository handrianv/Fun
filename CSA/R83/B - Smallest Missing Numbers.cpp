/*
    Sort the array. Then for each adjacent number that are not consecutive, we know how many missing number there is and we can get the sum using arithmetic progression formula.
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

ll Prog(ll first, ll last)
{
    ll n = last-first+1;
    ll s = last+first;
    return (n % 2 == 0) ? n/2*s : s/2*n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for(auto& v : vec) cin >> v;
    vec.push_back(0); vec.push_back(2e9);
    sort(vec.begin(), vec.end());

    int cntMissing = 0; ll ans = 0;
    for(int i = 1; i <= n+1; ++i)
    {
        int d = vec[i]-vec[i-1]-1;
        if(cntMissing + d >= m)
        {
            ans += Prog(vec[i-1]+1, vec[i-1]+m-cntMissing);
            break;
        }
        else
        {
            ans += Prog(vec[i-1]+1, vec[i]-1);
            cntMissing += d;
        }
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 