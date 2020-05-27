/* 
    A number with prime factorization p1^e1, p2^e2, ... pn^en have (e1+1) * (e2+1) * ... (en+1) divisors
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
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef pair<bool, int> pbi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXNUM = 1e4+5;
bool isPrime[MAXNUM];
int cnt[MAXNUM];
vector<int> primes;

void Factorize(int x)
{
    for(auto& prime : primes)
    {
        if(prime > x) break;
        while(x % prime == 0)
        {
            ++cnt[prime];
            x /= prime;
        }
    }
    if(x > 1) ++cnt[x];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    memset(isPrime, true, sizeof(isPrime)); primes.reserve(MAXNUM);
    for(int i = 2; i <= 100; ++i)
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

    for(int i = 0; i < 10; ++i)
    {
        int x;
        cin >> x;
        Factorize(x);
    }

    int ans = 1;
    for(int i = 2; i < 1e4; ++i)
    {
        (ans *= (cnt[i] + 1)) %= 10;
    }
    cout << (ans % 10) << "\n";
    return 0;  
}