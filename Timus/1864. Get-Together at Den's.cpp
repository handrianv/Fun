/*
    Assume n includes Den as well, so n = n+1.
    Denote sum of juices as S, then every person should get S / n.
    For every person, the amount of extra juice E[i] he should get is a[i] - S/n == (n*a[i] - S) / n. Convert to zero if negative.
    The sum of every extra juice is K/n, where K is the sum of numerator of every E[i].
    Then the money person i should get is E[i]/(K/n) == E[i] * n / K  == (n*a[i]-S)/K, multiplied by 100.
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, sum = 0;
    cin >> n;
    ++n;
    vector<int> vec(n);
    for(int i = 0; i < n-1; ++i)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    int extra = 0;
    for(auto& x : vec)
    {
        x = max(0, x*n-sum);
        extra += x;
    }

    for(int i = 0; i < n-1; ++i)
    {
        cout << (vec[i] * 100 / extra);
        (i+1 == n) ? cout << "\n" : cout << " ";
    }
    return 0;
}
