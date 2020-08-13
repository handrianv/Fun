/*
    The important observation is that the answer won't exceed 1 million
    Why? Because the input number is at most 1 million. Above base 1e6, every number <= 1e6 is written exactly the same way.
    A smaller example might be helpful. Consider the number 5, below base 6, the number 5 can be written in various ways:
    -. (101) in base 2
    -. (12) in base 3
    -. (11) in base 4
    -. (10) in base 5
    etc
    But starting with base 6 and above, it's written as just 5.

    With this observation, we can just brute force the minimal base
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

const int MAXNUM = 1e6;

void Convert(int num, const int& base, vector<int>& result)
{
    result.clear();
    while(num > 0)
    {
        result.push_back(num % base);
        num /= base;
    }
    //reverse(result.begin(), result.end());
}

bool Check(const vector<int>& x, const vector<int>& y)
{
    int yPtr = 0, yLen = y.size();
    for(auto& v : x)
    {
        if(v == y[yPtr])
        {
            ++yPtr;
            if(yPtr == yLen) return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int x, y;
    cin >> x >> y;
    
    vector<int> tx, ty;
    for(int base = 2; base <= MAXNUM; ++base)
    {
        Convert(x, base, tx); Convert(y, base, ty);
        if(Check(tx, ty))
        {
            cout << base << "\n";
            return 0;
        }
    }
    cout << "No solution\n";
    return 0;
}

/*

*/  