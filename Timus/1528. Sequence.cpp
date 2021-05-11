/*
    The function g seems rather arbitrary. Often, a good approach to this kind of problem is to simply write (or print) out several values of the 
    function, hoping to notice some pattern.
    We observe that g(n) seems to be just n, and indeed this is easily proved by induction. The base case is given and is true g(1) = 1. 
    For the inductive step, suppose it's true for g(n-1), then 
    -. g(n) = 1 + 2(g(1) + g(2) + .. + g(n-1)) - g(n-1)g(n-1)
    -. g(n) = 1 + n*(n-1) - (n-1)(n-1) -> by the inductive hypothesis and identity 1+2+..+n = n*(n+1)/2
    -. g(n) = n

    Next, we print the values of f, and notice that it's the factorial function. This can also be proved by induction. It's true for f(1) = 1 = 1!
    For the inductive step, suppose f(k) = k! for all k < n, we want to prove:
    -. f(n) = n! = 1 + 1f(1) + 2f(2) + .. + (n-1)f(n-1)
    -. n! = 1 + 1! + 2*2! + .. + (n-1)(n-1)!
    -. n! = (n-1)! + (n-1)(n-1)! -> by applying the 1 + 1! + .. + (n-2)(n-2)! = f(n-1) = (n-1)!
    -. n! = (n-1)! * (1 + (n-1)) = (n-1)! * n

    Finally, we solve each test case by linearly computing the factorial and taking modulo. n = 10^4 and there are 5000 tc, but somehow this passed in 0.39s lol.
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
    ll n, p;
    while(cin >> n >> p)
    {
        if(n == 0 && p == 0) return 0;
        ll ans = 1;
        for(int i = 2; i <= n; ++i)
        {
            ans = (ans*i)%p;
        }
        cout << ans << "\n";
    }
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/  