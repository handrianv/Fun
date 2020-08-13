/*
    Hint: Pigeonhole

    Hint 2: Prefix sum

    Solution:
    We have n prefix sums. Either there is a prefix sum with remainder 0 mod n, or there are two prefix sum with equal remainder > 0, which can be subtracted to get one with remainder 0.
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
    vector<int> vec(n+5);
    for(int i = 1; i <= n; ++i)
    {
        cin >> vec[i];
    }

    vector<vector<int>> remIdx(n);
    remIdx[0].push_back(0);
    int psum = 0;
    for(int i = 1; i <= n; ++i)
    {
        psum += vec[i];
        psum %= n;
        remIdx[psum].push_back(i);
    }

    for(int rem = 0; rem < n; ++rem)
    {
        if(remIdx[rem].size() > 1)
        {
            //cout << "Found at rem " << rem << "\n";
            int len = remIdx[rem][1] - remIdx[rem][0];
            cout << len << "\n";
            for(int i = remIdx[rem][0]+1; i <= remIdx[rem][1]; ++i)
            {
                cout << vec[i] << "\n";
            }
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}

/*

*/  