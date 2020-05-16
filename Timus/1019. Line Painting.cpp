/* 
    Coordinates are big but number of interval is small. So we can compress the intervals and just do naive simulation
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

struct Interval 
{
    int left, right, color;
    Interval(){}
    Interval(int l, int r, char c) : left(l), right(r), color((c == 'w')) {}
};

int Len(int left, int right)
{
    return (right - left);
}

void GetMx(int left, int right, int& ansLeft, int& ansRight)
{
    if(Len(left, right) > Len(ansLeft, ansRight))
    {
        ansLeft = left;
        ansRight = right;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    ++n;
    vector<Interval> queries(n);
    queries[0] = Interval(0, 1e9, 'w');

    // For compression
    vector<int> sorted; sorted.reserve(2*n+5);
    sorted.push_back(0); sorted.push_back(1e9);

    for(int i = 1; i < n; ++i)
    {
        int l, r; char c;
        cin >> l >> r >> c;
        queries[i] = Interval(l, r, c);
        sorted.push_back(l); sorted.push_back(r);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());;

    vector<int> vec(sorted.size());
    for(int i = 0; i < n; ++i)
    {
        auto q = queries[i];
        int left = lower_bound(sorted.begin(), sorted.end(), q.left) - sorted.begin();
        int right = lower_bound(sorted.begin(), sorted.end(), q.right) - sorted.begin();
        for(int j = left; j < right; ++j) vec[j] = q.color;
    }

    int currLeft = -1, currRight = -1000, ansLeft = -1, ansRight = -1000;
    for(int i = 0; i < (int)vec.size()-1; ++i)
    {
       // cout << "vec " << i << " color " << vec[i].first << " left/right " << vec[i].second << "\n";
        if(vec[i] == 1)
        {
            if(currLeft == -1) currLeft = sorted[i];
            currRight = sorted[i+1];
        }
        else
        {
            currLeft = -1; currRight = -1000;
        }
        
        GetMx(currLeft, currRight, ansLeft, ansRight);
    }
    
    cout << ansLeft << " " << ansRight << "\n";
    return 0;  
}