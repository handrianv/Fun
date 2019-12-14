/* 
    1. Swap adjacent element
    -. Every swap either increases / decreases number of inversion by 1.
    -. Only a sorted array have zero inversion.
    -. So answer is number of inversion

    2. Swap two element
    -. Draw the permutation graph and it will form several set of disjoint cycles. Each cycle takes (cycle length - 1) move to solve.

    3. Insert element in any position
    -. If an element is moved more than once, it can also be moved only once. So an element is either moved once or not at all.
    -. For the set of element we didn't move, they should already be sorted (i.e. they form an increasing subsequence).
    -. Then we want the longest increasing subsequence, and the answer is (n - LIS)

    4. Move element to front
    -. Similar observation to previous problem, an element is either moved once or not at all.
    -. For the set of element we didn't move, they should form longest possible suffix (k, k+1, ..., n); 
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
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

const int MAXN = 2e5+5;
int n;
int arr[MAXN] ,fenwick[MAXN];

void Add(int idx)
{
    while(idx <= n)
    {
        ++fenwick[idx];
        idx += LSOne(idx);
    }
}

int Query(int idx)
{
    int ans = 0;
    while(idx > 0)
    {
        ans += fenwick[idx];
        idx -= LSOne(idx);
    }
    return ans;
}

ll Solve1()
{
    ll inversion = 0;
    for(int i = n-1; i >= 0; --i)
    {
        inversion += Query(arr[i]-1);
        Add(arr[i]);
    }
    return inversion;
}

int Solve2()
{
    vector<int> nxt(n);
    for(int i = 0; i < n; ++i)
    {
        nxt[i] = arr[i]-1;
    }

    int ans = 0;
    vector<int> visited(n);
    for(int i = 0; i < n; ++i)
    {
        if(visited[i]) continue;
        int cycle = 0;
        while(!visited[i])
        {
            visited[i] = true;
            i = nxt[i];
            ++cycle;
        }
        ans += (cycle-1);
    }
    return ans;
}

int Solve3()
{
    vector<int> vec;
    for(int i = 0; i < n; ++i)
    {
        auto iter = lower_bound(vec.begin(), vec.end(), arr[i]);
        if(iter == vec.end()) vec.push_back(arr[i]);
        else (*iter) = arr[i];
    }
    return (n-vec.size());
}

int Solve4()
{
    vector<int> pos(n+5);
    for(int i = 0; i < n; ++i) pos[arr[i]] = i;
    int suffix = 1;
    for(int i = n-1; i > 0; --i)
    {
        if(pos[i] < pos[i+1]) ++suffix;
        else break;
    }
    return (n-suffix);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << Solve1() << " " << Solve2() << " " << Solve3() << " " << Solve4() << "\n";
    return 0; 
}
