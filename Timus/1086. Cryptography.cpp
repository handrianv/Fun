/* 
    Approximate number of primes below x = x/ln(x)
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

const int MAXN = 200000;
bool isPrime[MAXN+5];
vector<int> primes;

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
            for(int j = i+i; j < MAXN; j += i) isPrime[j] = false;
        }
    }
    int k;
    cin >> k;
    while(k--)
    {
        int n;
        cin >> n;
        cout << primes[n-1] << "\n";
    }
    return 0; 
}       