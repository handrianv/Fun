/*
    This is also https://www.spoj.com/problems/INCSEQ/
    
    We want to count number of decreasing subsequences of length k. The trick is to try solving it for easy cases first, then generalize.
    Let vec[i] be the number at index i.
    
    k = 2
    Then for each i, we just need to count how many vec[j] > vec[i], j < i.

    k = 3
    Similar to k=2 case, but this time we needs 2 elements before vec[i]. So we need to count how many vec[k] > vec[j] > vec[i], k < j < i. But we
    just solved the case k=2 above! So if we let vec2[j] -> how many subsequences of length 2 vec[k] > vec[j], then to solve k=3 we just need
    to count vec2[j] > vec[i], j < i.

    Generalizing, we can come up with the following dp:
    State
    dp[i][k] -> how many valid subsequences ending at vec[i] with length k.

    Transition
    dp[i][k] -> Sum(all vec[j] > vec[i]) dp[vec[j]][k-1]
    
    Since for the transition we need to query all dp[vec[j]][k-1] for vec[j] > vec[i], we can speed it up by storing the (k-1)'th dp in range sum query data structure.
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

const int MOD = 1e9;

#define LSOne(S) (S & (-S))
template <typename T>
struct Fenwick
{
    vector<T> vec;
    Fenwick(int n) : vec(n) {}

    void add(int pos, T val)
    {
        int n = (int)vec.size();
        while (pos <= n)
        {
            vec[pos] += val;
            if (vec[pos] >= MOD)
                vec[pos] -= MOD;
            pos += LSOne(pos);
        }
    }

    T query(int pos)
    {
        T res = 0;
        while (pos > 0)
        {
            res += vec[pos];
            if (res >= MOD)
                res -= MOD;
            pos -= LSOne(pos);
        }
        return res;
    }

    T query(int left, int right)
    {
        T qr = query(right);
        T ql = (left == 0) ? 0 : query(left - 1);
        T res = qr - ql;
        if (res < 0)
            res += MOD;
        return res;
    }
};

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(auto& v : vec)
    {
        cin >> v;
    }

    Fenwick<int> fenwick(n+5); // Stores dp of k-1 inversions
    vector<vector<int>> dp(k+5, vector<int>(n+5));
    fill(dp[1].begin(), dp[1].end(), 1);
    for(int i = 2; i <= k; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int num = vec[j];
            dp[i][num] += fenwick.query(min(n, num+1), n);
            if(dp[i][num] >= MOD) dp[i][num] -= MOD;
            fenwick.add(num, dp[i-1][num]);
            //cout << "dp[" << i << "][" << num << "] = " << dp[i][num] << "\n";
        }


        // Reset fenwick 
        for(int j = 1; j <= n; ++j)
        {
            fenwick.vec[j] = 0;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans += dp[k][i];
        if(ans >= MOD) ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/  