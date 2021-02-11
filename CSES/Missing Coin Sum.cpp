/*
    Let's analyze some easy cases first. We sort the array, then:
    -. If a[0] is not 1, then the answer is 1, because we can't make 1 and we know all next elements will be > 1.
    -. Suppose a[0] = 1. Then what is the lower bound for a[1]? Clearly it's 2. If a[1] > 2, we can't make 2, else we can make 2 and / or 3, depending
       on the value of a[1].

    You can try a few more cases and see that this can be generalized. Suppose we are at a[i], and we know we can make all numbers [1, k] using subset
    of elements from set S = {a[0], a[1], ..., a[i-1]}
    -. If a[i] > k+1, then we are done and the answer is k. This should be clear enough. We cannot make k+1 using S, and adding a[i] > k+1 won't help.
    -. Else a[i] <= k+1 and we can now make all numbers 1 <= X <= (k+a[i]) as follows:
       --. If 1 <= X <= k, we can make it with elements in S. Remember we already asserted that we can make all numbers [1, k] using just subset of S.
       --. Else we can make X-a[i] (which must be <= k) using S, and after that add a[i].
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
    vector<int> vec(n);
    for(auto& v : vec)
    {
        cin >> v;
    }
    sort(vec.begin(), vec.end());
    ll ans = 1;
    for(auto& v : vec)
    {
        if(v > ans)
        {
            break;
        }
        ans += v;
    }
    cout << ans << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
setprecision for doubles!! Costed me half a day of life!!
*/  