/* 
    Approach #1: 
        Pollard rho

    Approach #2:
        Using naive factorization algorithm, we would need to generate primes up to sqrt(1e18), but we can do some pruning.

        Let's review the naive algorithm and see why given a number N, we only need to generate primes up to sqrt(N). Write N as:
        p1^(a1) * p2^(a2) * ... * pn^(an) where p(i) < p(i+1)
        And we don't actually generate primes up to pn, but only up to p(n-1). After dividing by all primes up to p(n-1) if the remainder > 1 then we get pn
        What is the largest prime p(n-1) can be? It happens when pn == sqrt(N) so p(n-1) is also sqrt(N) and we generate primes up to it.

        In this problem we know n = 20, so we need to generate up to p19. What is the largest prime possible for p19?
        It happens when p1, p2, until p18 are all 2. So p19*p20 == (1e18 / 2^18) and p19 is maximized when it is the sqrt of the rhs.
        It's roughly 2 million, so we can just do naive algorithm.
*/

#include <stdio.h>
#include <bits/stdc++.h>
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
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 2e6+5;
bool isPrime[MAXN];
vector<int> primes;

bool Factorize(ll n)
{
    int psum = 0;
    for(const auto& prime : primes)
    {
        if(prime > n) break;
        while(n % prime == 0)
        {
            n /= prime;
            ++psum;
        }
    }
    if(n > 1) ++psum;
    return (psum == 20);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i < MAXN; ++i)
    {
        if(!isPrime[i]) continue;
        primes.push_back(i);
        for(int j = i+i; j < MAXN; j += i)
        {
            isPrime[j] = false;
        }
    }

    ll n;
    cin >> n;
    (Factorize(n)) ? cout << "Yes\n" : cout << "No\n";
    return 0; 
}       