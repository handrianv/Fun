/*
    First do the same thing as Collecting Numbers.cpp.
    It might be easier to visualize this as directed graph. From each number i there is an outgoing edge to (i+1). Then the answer is count of 
    edges directed to the left.

    When a number changes position, it's easy to see that only 2 edges are affected: the incoming edge to this number and its outgoing edge. Then 
    recomputing the answer is a matter of checking whether the new edge changes direction.
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
    vector<int> vec(n), idx(n+5);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        idx[vec[i]] = i;
    }

    int ans = 1;
    for(int i = 1; i < n; ++i)
    {
        ans += (idx[i] > idx[i+1]);
    }

    auto HandleIn = [&](int pos, int npos)
    {
        int num = vec[pos];
        if(num == 1) return;
        if(idx[num-1] < pos && idx[num-1] > npos) ++ans;
        else if(idx[num-1] > pos && idx[num-1] < npos) --ans;
    };
    
    auto HandleOut = [&](int pos, int npos)
    {
        int num = vec[pos];
        if(num == n) return;
        if(pos < idx[num+1] && npos > idx[num+1]) ++ans;
        else if(pos > idx[num+1] && npos < idx[num+1]) --ans;
    };
    
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int na = vec[a], nb = vec[b];

        if(abs(na-nb) == 1)
        {
            if(na > nb)
            {
                swap(a, b);
                swap(na, nb);
            }

            // Out edge of a
            if(a < b) ++ans; else --ans; 
        }
        else
        {
            // Out edge of a
            HandleOut(a, b);
        }

         // In edge of a
        HandleIn(a, b);
        // Out edge of b
        HandleOut(b, a);
        // In edge of b
        HandleIn(b, a);
        
        swap(vec[a], vec[b]);
        idx[na] = b; idx[nb] = a;
        cout << ans << "\n";
    }
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
setprecision for doubles!! Costed me half a day of life!!
*/  