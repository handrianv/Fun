/*
    The problem wording is kinda ambiguous. The restriction is "every" consecutive three digit must be a three-digit prime number.
    
    Now, for every three consecutive digit, the first number and the second number is connected by its last two suffix and prefix respectively.
    E.g. 1317 is made of "131" and "317", connected by "31" which is a suffix of "131" and prefix of "317".
    This gives an idea for dynamic programming:
    -. State: dp[n][x] = how many valid number of length n, ending with suffix x, where x ranges from 01-99.
    -. Transition: Suppose we want to check dp[n][43], that is, how many number ends with suffix "43".
                   Then we should add every dp[n-1][y4] where y is a digit ranging from 0-9
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

const int MAXN = 1e4+5, MAXNUM = 1000, MOD = 1e9+9;
bool isPrime[MAXNUM];
int dp[MAXN][100];

vector<int> GenPrime()
{
    vector<int> primes;
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i < MAXNUM; ++i)
    {
        if(isPrime[i])
        {
            if(i > 100) primes.push_back(i);
            for(int j = i*i; j < MAXNUM; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<int> primes = GenPrime();
    set<int> suffixes; // last two digit of each prime
    vector<vector<int>> suffixPair(105); // possible first digit for each suffix 
    for(auto& prime : primes)
    {
        int lastTwo = prime % 100;
        suffixes.insert(lastTwo);
        suffixPair[lastTwo].push_back(prime / 100);
        ++dp[2][lastTwo];
    }

    int n;
    cin >> n;
    for(int i = 3; i < n; ++i)
    {
        for(auto& suffix : suffixes)
        {
            for(auto& sp : suffixPair[suffix])
            {
                dp[i][suffix] += dp[i-1][sp*10 + suffix/10];
                if(dp[i][suffix] >= MOD) dp[i][suffix] -= MOD;
            }
        }
    }

    int ans = 0;
    for(auto& suffix : suffixes)
    {
        ans += dp[n-1][suffix];
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}
 
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/