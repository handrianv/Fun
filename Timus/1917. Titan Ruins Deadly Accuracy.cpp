/*
    Problem clarification: The value p stays the same in-between spells.
    So if before casting a spell our p is 7, and we cast a spell with power 3 that destroyed 2 coins, our hp is NOT reduced to 1, but stays 7.

    First let's ignore the "minimum number of spells" restriction and focus on how to destroy the maximum number of coins. Sort the coins by their resistance in non-descending order. Let r[i] be the resistance of the i'th coin.
    -. Then we should only cast spell with power p such that p = r[i] for some i.
       Proof is simple: If we cast spell with power r[i] < p < r[i+1], we destroy all coins up to the i'th with each costing p. We can reduce p to r[i] and still destory the same amount of coins with less cost.
    -. Next observation is we should destroy all coins up to the (i-1)'th before destroying the i'th. This should be quite easy to see.
    So we can just destroy the coins in non-descending order, each time using spell with power equal to the current r[i].

    Now for the minimum number of moves. We should "merge" the destruction of some coins. We can do it greedily, each time merging as long prefix as possible.
    Proof: Suppose in our first cast, we destroy 1st up to i'th coin. In second cast, we destroy (i+1)'th coin up to the j'th coin.
    If we can actually destroy the (i+1)'th coin in the first cast, we should do so, because the answer can get potentially better, but never worse. The first cast will still be valid,
    and the cost of second cast is reduced (potentially turning it from invalid cast to a valid one, but never vice versa)
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
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    ll n, p;
    cin >> n >> p;
    map<ll, ll> m;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++m[x];
    }
    vector<pll> vec; vec.reserve(n);  // {num, freq}
    for(auto& kv : m) vec.push_back(kv);
    
    // Without considering minimal number of move, check maximal number of coins we can destroy
    // Use spell with power equal to r[i] each time
    ll totDestroyed = 0, cpy = p;
    vector<pll> used; used.reserve(n);
    for(auto& v : vec)
    {
        if(p >= (v.first * v.second))
        {
            totDestroyed += v.second;
            used.push_back(v);
        }
        else break;
    }
    p = cpy;

    cout << totDestroyed << " ";
    if(totDestroyed == 0)
    {
        cout << "0\n";
        return 0;
    }

    // Each time, merge the destruction of as long prefix as possible
    int minMove = 1; ll temp = 0;
    for(auto& v : used)
    {
        temp += v.second;
        if(temp * v.first > p)
        {
            ++minMove;
            temp = v.second;
        }
    }
    cout << minMove << "\n";

    return 0;
}
 
/*
 
*/ 