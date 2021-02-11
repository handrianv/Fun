/*
    Consider a number i. Let idx[i] be the index of number i in the array. If idx[i] < idx[i+1], then they will be collected on the same turn.
    Otherwise, they will be collected on separate turns.
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
    int n;
    cin >> n;
    vector<int> idx(n+5);
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        idx[x] = i;
    }
    
    int ans = 1;
    for(int i = 1; i < n; ++i)
    {
        ans += (idx[i] > idx[i+1]);
    }
    cout << ans << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
setprecision for doubles!! Costed me half a day of life!!
*/  