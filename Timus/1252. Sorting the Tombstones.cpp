/*
    Recall that we can create a permutation graph out of a permutation by drawing directed edge from v[i] to i. The resulting graph will be composed of several disjoint cycles.

    Let's analyze one such cycle, suppose it consists of 3 edges of length 4, 8, and 10 respectively. The problem is asking us to pick the maximum possible K such that we can sort this cycle by 
    only swapping indices K distance apart. What is the largest K that can cover 4, 8, and 10? It's just the gcd! Which in this case is 2.

    Now we have several cycles, and we want a number that can cover the gcd of each cycle. We just take the gcd of all gcd.
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;

void Compress(vector<int>& vec)
{
    vector<int> sorted = vec;
    sort(sorted.begin(), sorted.end());
    for(auto& v: vec)
    {
        v = lower_bound(sorted.begin(), sorted.end(), v) - sorted.begin();
    }
}

int Try(const vector<int>& vec, bool ascending)
{
    int g = 0;
    vector<char> visited(n);
    for(int i = 0; i < n; ++i)
    {
        int curr = i;
        while(!visited[curr])
        {
            visited[curr] = true;
            int nxt = (ascending) ? vec[curr] : n-1-vec[curr];
            g = __gcd(g, abs(curr-nxt));
            curr = nxt;
        }
    }
    if(g == 0) g = n;
    return g-1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    vector<int> vec(n);
    for(auto& v : vec)
    {
        cin >> v;
    }
    Compress(vec);
    cout << max(Try(vec, true), Try(vec, false)) << "\n";

    return 0;
}
 
/*
 
*/  