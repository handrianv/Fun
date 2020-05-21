/* 
    We can work on the permutation graph. For a cycle in the graph with length L, an identity permutation is achieved when k = m * L for m > 0.
    For each disjoint cycle with length L1, L2, .. Ln, we need to find smallest k such that it's a multiple of all of them, which is just LCM.

    Answer is guaranteed to be <= 1e9, so we can avoid using long long by doing division before multiplication when computing LCM.
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n+5);
    for(int i = 1; i <= n; ++i) cin >> vec[i];

    int ans = 1;
    vector<int> visited(n+5);
    for(int i = 1; i <= n; ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            int curr = i, len = 0;
            do {
                curr = vec[curr];
                visited[curr] = true;
                ++len;
            } while(curr != i);

            //cout << "len is " << len << "\n";
            ans = ans / __gcd(ans, len) * len;
        }
    }
    cout << ans << "\n";
    return 0;  
}