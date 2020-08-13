/*
    First we can observe that the answer won't be larger than 10001, because the least range we can be given is P = 0.00 and Q = 0.01, and with 10001 citizen it's still enough to get us 1 citizen.
    Now we can just brute force all possible number of citizens. For each number N we try, we can check whether the first integer larger than P% * N is less than Q% * N.
    For this to work we will need long double
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
    ld p, q;
    cin >> p >> q;
    for(int i = 1; ; ++i)
    {
        int target = (i * p / 100 + 1);
        ld need = (ld)target * 100.0 / i;
        if(need > p && need < q)
        {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}

/*

*/  