/*
    First of all, Alex should obviously take all positive numbers.
    Now we are left with only negative numbers, and Alex would like to make his sum as small as possible.
    Sort the array. It turns out that the best move for Alex is to take things alternatingly e.g. take all elements in odd / even position, and Ben will take the other parity.
    For Ben it's obvious, he should just take the smallest number possible in each move.
    For Alex, suppose there is some set of moves and in this set of moves there is a move where Alex takes K > 1 elements.
    Then he can change it to taking (K-1) elements, Ben will take the other element. Every other move stays the same, so Alex's sum is reduced.

    The rest is case bashing: check whether it's optimal for Alex to start from odd / even parity.
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec; vec.reserve(n);
    ll sum = 0; bool hasNonNegative = false;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if(x >= 0)
        {
            sum += x;
            hasNonNegative = true;
        } 
        else vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    
    int sz = vec.size(), start = (sz % 2 != 0) ? 1 : 0;
    if(!hasNonNegative && start == 1) // If there is no non-negative, for Alex to start at even position he'd need to take the first number as well.
    {
        sum += vec[0];
    }
    //cout << "start is " << start << "\n";
    for(int i = start; i < sz; i += 2)
    {
        sum += vec[i];
    }
    cout << sum << "\n";
    return 0;
}

/*

*/