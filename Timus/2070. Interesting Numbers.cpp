/*
    S = Satisfying number, NS = Not Satisfying number.
    P = Prime number, prime amount of divisor
    PC = Prime number, composite amount of divisor. This is impossible.
    CP = Composite number, prime amount of divisor.
    CC = Composite number, composite amount of divisor
    We have two choices, look for S or NS.
    -.  Look for S
        We should search both P and CC. Searching P up to 10^12 is infeasible, so we cannot look for S.
    -.  Look for NS
        We should search for CP.
        Recall that to get the amount of divisor of a number N, we can write its Prime Factorization: a^n, b^m, .. x^y
        Then D(N) = (n+1) * (m+1) * ... (y+1). D(N) is amount of divisor of N. E.g D(10) = 4.
        We want D(N) to be prime, so the amount of distinct prime factor cannot be larger than 1, else D(N) is a multiple of some number which makes it composite.
        Now we know the number must have only one prime factor. So N = a^n. D(N) = (n+1).
        For D(N) to be prime, n must be one below a prime, except n == 1 (because a^(1) is a prime, which is in S).
        So now, to get the amount of NS from [1...X]:
        -. We loop through every prime factor PF from 2...X
           For every number, we start evaluating every power that is one below prime (except 1).
           From PF^2, PF^4, PF^6, PF^(10) ... until it is larger than X.
           Since we start evaluating from power of 2, we only need to generate prime up to 10^6 (because the limit is only 10^12).
           After that we can use inclusion-exclusion to get answer.
    NOTE: There is an overflow bug in below code. Fortunately, because of how overflow behave when type is unsigned long long, it still gets accepted.
          But that's just luck, it's much better to implement this in Java / Python.
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

const int MAXNUM = 1e6+5;
bool isPrime[MAXNUM];
vector<int> primes;

ll Solve(ll r)
{
    ll ans = 0;
    for(auto& prime : primes)
    {
        int p = 2; ll curr = (ll)prime*prime;
        while(curr <= r)
        {
            ans += isPrime[p+1];
            ++p;
            curr *= prime;
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i < MAXNUM; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(int j = i+i; j < MAXNUM; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    ll l, r;
    cin >> l >> r;
    cout << (r-l+1) - (Solve(r) - Solve(l-1)) << "\n";
    return 0;
}