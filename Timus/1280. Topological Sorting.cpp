/*
    Given an ordering, check if it is a valid topological ordering.

    Algorithm:
    It's enough to check for each edge (vi, vj), the occurence of vi in the ordering is before vj.

    Self note:
    Why is checking only "direct" ordering enough? How does this guarantee that the ordering is also correct transitively?
    E.g. We have v1 before v2, v2 before v3. How does this algorithm guarantee v1 also comes before v3?
    
    Summarized question:
    How does the algorithm guarantee that it also detects transitively incorrect ordering, by just checking direct ordering

    Lemma:
    In an invalid topological order, it there exist a transitively invalid ordering, there must also exist directly invalid ordering.

    Hint:
    Prove it the same way we prove array inversion. If there exist a non-adjacent inversion, there must also exist adjacent inversion

    Proof:
    Suppose the ordering is vi, vi+1, ... vj, vi and vj are transitively incorrect. We analyze two cases:
    -. If ordering between vi and vi+1 is correct, then ordering between vi+1 and vj is incorrect. If j = i+1, then they're directly invalid and we're done. Else we repeat this argument with vi+2
    -. If ordering between vi and vi+1 is invalid, then they're directly invalid and we're done.
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
    int n, m;
    cin >> n >> m;
    vector<pi> edges(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> idxOf(n+5);
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        idxOf[x] = i;
    }

    bool valid = true;
    for(auto& edge : edges)
    {
        if(idxOf[edge.first] > idxOf[edge.second])
        {
            valid = false;
            break;
        }
    }

    (valid) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
     
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/