/*
    Correction to the problem statement: We can go from n to a number "divisible" by n.

    First, a should divide b, else the answer is 0.
    Now we should multiply a by some number until it's equal b. We want to multiply as many times as possible.
    Then in each step we should multiply by a prime number. If we multiply by a composite number, it can be separated into several steps of multiplication by prime number.
    So for every prime factor p in b, if p occurs i times in b and j times in a, we can multiply by p (i-j) times.
    It's guaranteed that i >= j, since we already verified b is divisible by a.
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
 
const int MAXN = 31630;
bool isPrime[MAXN];
vector<int> primes;

vector<pi> Factorize(int a)
{
    vector<pi> factors;
    for(auto& prime : primes)
    {
        int cnt = 0;
        while(a % prime == 0)
        {
            a /= prime;
            ++cnt;
        }
        if(cnt > 0) factors.push_back({prime, cnt});
    }
    if(a > 1) factors.push_back({a, 1});
    return factors;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i < MAXN; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(int j = i+i; j < MAXN; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;

        int ans = 1;
        if(b % a == 0)
        {
            vector<pi> factors = Factorize(b);
            for(auto& factor : factors)
            {
                int cntA = 0;
                while(a % factor.first == 0)
                {
                    a /= factor.first;
                    ++cntA;
                }
                ans += (factor.second-cntA);
            }
        }
        else ans = 0;

        cout << ans << "\n";
    }
    return 0;
}
 
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/