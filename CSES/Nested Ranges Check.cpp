/*
    As is often with segments problem, we can sort the segments to turn the problem into one-dimensional.
    We'll discuss how to solve the first query: " determine for each range if it contains some other range". The second query is similar.
    
    Sort the segments by their x, breaking ties by descending y. 
    Let s[i] be the i'th segment. Now for any s[i], it can only contain segments to its right i.e. s[j > i]. If j < i then due to sorting we know
    that the left endpoint will not be contained (or in case of tie, the right endpoint will not be contained).

    For any s[j] to be contained within s[i], then we need at least one s[j].y <= s[i].y (remember that by sorting we already know s[j].x >= s[i].x)
    and this is easy to check by maintaining suffix minimum.
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
    std::ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<pi, int>> vec(n); // {{left, right}, index}
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i].first.first >> vec[i].first.second;
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end(), 
    [](const pair<pi, int>& a, const pair<pi, int>& b)
    {
        if(a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first < b.first.first;
    });

    int mnRight = 2e9;
    vector<int> ans1(n);
    for(int i = n-1; i >= 0; --i)
    {
        ans1[vec[i].second] = (mnRight <= vec[i].first.second);
        mnRight = min(mnRight, vec[i].first.second);
    }

    int mxRight = -1;
    vector<int> ans2(n);
    for(int i = 0; i < n; ++i)
    {
        ans2[vec[i].second] = (mxRight >= vec[i].first.second);
        mxRight = max(mxRight, vec[i].first.second);
    }

    for(int i = 0; i < n; ++i) cout << ans1[i] << " \n"[i+1 == n];
    for(int i = 0; i < n; ++i) cout << ans2[i] << " \n"[i+1 == n];
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/  