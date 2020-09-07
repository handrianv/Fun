/*
    The observation is that we only have about 20 power of three's before reaching 4294967291, so we can brute force all possible combination of sum we can make 
    with these power of 3's
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
    vector<unsigned int> p3;
    p3.push_back(1);
    for(int i = 1; i < 21; ++i)
    {
        unsigned int curr = p3.back() * 3;
        p3.push_back(curr);
    }

    int n;
    cin >> n;
    int sz = p3.size();
    vector<unsigned int> sums; sums.reserve((1<<sz)+5);

    for(int i = 0; i < (1<<sz); ++i)
    {
        unsigned int sum = 0;
        for(int b = 0; b < sz; ++b)
        {
            if(i & (1<<b))
            {
                sum += p3[b];
            }
        }
        if(sum > n && (*lower_bound(sums.begin(), sums.end(), sum-n) == sum-n))
        {
            cout << sum << " " << sum-n << "\n";
            return 0;
        }
        sums.push_back(sum);
    }
    cout << "0\n";
    return 0;
}
 
/*
 
*/  