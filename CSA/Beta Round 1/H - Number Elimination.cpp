/*
    First, let's analyze the case when there is only 1 kind of number, say 5
    (5 5 5 5)
    Then we have C(4, 2) choices for the first move, and no matter which choice we pick there will be only 3 numbers remaining.
    So if ways[i] is the number of ways to reduce i kind of the same number to one, we have ways[i] = C(i, 2) * ways[i-1]

    Now suppose we have multiple numbers, each grouped together. For example
    (5 5) (6 6 6) (7 7 7 7) 
    Let's first analyze the optimal strategy, without bothering to count number of ways.
    The first obvious observation is a number x should be paired with another number x for its elimination, unless it's the only x left.
    For example, we should never eliminate 5 with any y > 5 if there are more than one 5 left, because by pairing it with another 5 we get the same result with less cost.
    When x is the only one of its kind, it should be eliminated with the first y > x. So in the example the last 5 must be paired with 6. The same reasoning applies, we can get the same result with less cost.

    This is the only optimal strategy. So if we have n group of numbers, we can do:
    1. Reduce the first (n-1) group to one number
    2. Pair with with any number in the n'th group
    3. Reduce the n'th group to one number 
    The second action can only be done after the first one, but other than that there are no restrictions on the order of move. 
    
    Now let's go to counting. We'll still refer to this test case (5 5) (6 6 6) (7 7 7 7). 
    n = 3
    Suppose dp[n] is the number of ways to reduce n group of number to a single number

    We have dp[n-1] ways to reduce the first (n-1) group to one number
    (6) (7 7 7 7)

    Now we can pair this 6 with any of the number in the n'th group. Suppose we want to pair it when the n'th group only have 1 element left. 
    (6) (7)
    There are ways[4] way to reduce the last group to a single 7

    What if we want to pair it when the size of the n'th group is 2?
    (6) (7 7) -> after this pair 6 with any of the 7
    Turns out there are also ways[4] way to reduce 7 to 2 elements. Why?
    Because for every way in ways[4] way to reduce the 7's to a single number, the size x appears exactly once.
    Imagine all ways[4] way of reducing (7 7 7 7) to a single (7), in each of those way, there must be a point where it's (7 7) or (7 7 7) or (7)
    So there are also ways[4] way to reduce (7 7 7 7) to any x number of 7

    So if x is the remaining element in the n'th group when we pair it with the 6, we have
    dp[n] = Sum(x = 1 until sz(n)(=4 in this case)) dp[n-1] * ways[4]
    Okay, then the last number can be paired with any of the remaining x element, so
    dp[n] = Sum(x=1->x=4) dp[n-1] * ways[4] * x

    Only one remaining part. We don't have to reduce the first (n-1) group to single element before we start eliminating the 7's. We can also eliminate the 7's in-between
    For example, consider one possible way of reducing (5.1 5.2) (6.1 6.2 6.3) to single 6. The dot is just to differentiate index
    (6.1, 6.3), (5.1 5.2), (5.2, 6.2), (6.2, 6.3)
    Consider we want to pair it with 7 when x=2, one such way of reducing 7 to 2 element
    (7.1, 7.2), (7.2, 7.3)
    Then one possible combination of moves is (6.1, 6.3) (5.1. 5.2) (7.1, 7.2) (5.2, 6.2) (7.2, 7.3) (6.2, 6.3)
    To count all ways, there are 6 moves
    _ _ _ _ _ _ -> fix any of the 2 moves for the 7's, and the rest is determined. So we have C(6, 2) ways
    More generally, for any of the dp[n-1] moves, we always need Sum(size(1)->size(n-1))-1 moves to reduce it to one element, and (sz(n)-x) moves of reducing it to x element
    So we have C( Sum(size(1)->size(n-1)) - 1 + size(n)-x, size(n)-x) ways to mix them

    So our final answer is
    dp[n] = Sum(x=1->x=n) dp[n-1] * ways[n] * x * C( Sum(size(1)->size(n-1)) - 1 + size(n)-x, size(n)-x)
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD = 1e9+7;
const int MAXN = 1e5+5;
ll fact[MAXN], invFact[MAXN];
ll ways[MAXN]; // How many ways to reduce group size i to 1 element

ll ModExponent(ll base, ll exponent, ll m)
{
    ll result = 1;
    while(exponent > 0)
    {
        if(exponent % 2 != 0)
        {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exponent /= 2;
    }
    return result;
}

ll ModInverse(ll x)
{
    return ModExponent(x, MOD-2, MOD);
}

void Preprocess()
{
    fact[0] = 1;
    for(ll i = 1; i < MAXN; ++i)
    {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invFact[MAXN-1] = ModInverse(fact[MAXN-1]);
    for(int i = MAXN-2; i >= 0; --i)
    {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }

    ways[1] = 1;
    for(int i = 2; i < MAXN; ++i)
    {
        if(i % 2 == 0)
        {
            ways[i] = (i/2*(i-1)) % MOD;
            ways[i] = (ways[i] * ways[i-1]) % MOD;
        }
        else
        {
            ways[i] = ((i-1)/2*i) % MOD;
            ways[i] = (ways[i] * ways[i-1]) % MOD;
        }
    }
}

ll Combination(int a, int b)
{
    ll nume = fact[a];
    ll denom = (fact[b] * fact[a-b]) % MOD;
    return ((nume * ModInverse(denom)) % MOD);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    Preprocess();
    int n;
    cin >> n;
    vector<int> tempvec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> tempvec[i];
    }
    sort(tempvec.begin(), tempvec.end());
    tempvec.push_back(-1);

    vector<pi> vec; vec.reserve(n); // {num, freq}
    int cnt = 1;
    for(int i = 1; i < (int)tempvec.size(); ++i)
    {
        if(tempvec[i] != tempvec[i-1])
        {
            vec.push_back({tempvec[i-1], cnt});
            cnt = 0;
        }
        ++cnt;
    }

    vector<ll> dp(vec.size());
    int sz = vec[0].second;
    dp[0] = ways[sz];

    for(int i = 1; i < (int)vec.size(); ++i)
    {
        int currSz = vec[i].second;
        // Remaining element of suffix
        for(int j = 1; j <= currSz; ++j)
        {
            ll temp = 0;
            // Number of ways to reduce prefix (i-1) group to 1 element, and this group to j element
            temp += (dp[i-1] * ways[currSz]);
            temp %= MOD;

            // Intertwine the moves of reducing prefix and suffix with stars and bars
            // The total number of moves must be (sz-1) + (currSz-j). Or in words, number of moves to reduce prefix to 1 element + to reduce suffix to j element
            // So by s&b there are Combination((sz-1+currSz-j), sz-1) ways to arrange them
            temp *= Combination(sz-1+currSz-j, sz-1);
            temp %= MOD;

            // Number of ways to match the one element of prefix to j remaining element in suffix
            temp *= j;
            temp %= MOD;

            (dp[i] += temp) %= MOD;
        }
       // cout << "dp " << i << " " << dp[i] << "\n";
        sz += currSz;
    }
    cout << dp.back() << "\n";
    return 0;
}

/*

*/