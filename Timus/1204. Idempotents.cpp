/*
    "==" means congruent
    First, we can rearrange the equation x^2 == x (mod n) to x * (x-1) == 0 (mod n)
    This is enough to get us O(sqrt(n)) solution per test case. We need to find all x < n that satisfy the conguruence
    The important thing to note is we are given n a semiprime of p * q. WLOG p <= q:
    -. Then p <= sqrt(n) and q >= sqrt(n)
    -. x >= q. Because if x < q then (x-1) also < q, so x*(x-1) doesn't have factor of q and thus not divisible by n
    -. Then either x or (x-1) is a multiple of q, and the other must be multiple of p. 
       We can brute force all multiple of q < n. We check at most p multiple of q (because n = p * q and we can't exceed n), and since p <= sqrt(n),
       there are at most sqrt(n) number we need to check. For each of them we try one of x and (x-1) to be multiple of q

    TODO: Solve this is exgcd
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

const int MAXNUM = 31700;
bool isPrime[MAXNUM];
vector<int> primes;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    memset(isPrime, true, sizeof(isPrime)); primes.reserve(MAXNUM);
    for(int i = 2; i < MAXNUM; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(int j = i*i; j < MAXNUM; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        int p, q;
        for(auto& prime : primes)
        {
            if(n % prime == 0)
            {
                p = prime;
                q = n / prime;
                break;
            }
        }
        set<int> ans = {0, 1};
        if((q+1) % p == 0) ans.insert(q+1);
        for(int i = 1; i < p; ++i)
        {
            if((i * q + 1) % p == 0) ans.insert(i*q+1);
            if((i * q - 1) % p == 0) ans.insert(i*q);
        }

        int sz = ans.size();
        for(auto& x : ans)
        {
            cout << x;
            --sz;
            (sz == 0) ? cout << "\n" : cout << " ";
        }
    }
    return 0;
}