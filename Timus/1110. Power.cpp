/* 

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

int ModExponent(int base, int exponent, ll m)
{
    ll result = 1;
    while(exponent > 0)
    {
        if(exponent % 2 != 0)
        {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        exponent /= 2;
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, MOD, y;
    cin >> n >> MOD >> y;

    vector<int> ans;
    for(int i = 0; i < MOD; ++i)
    {
        if(ModExponent(i, n, MOD) == y)
        {
            ans.push_back(i);
        }
    }
    
    if(ans.empty()) ans.push_back(-1);
    for(int i = 0; i < (int)ans.size(); ++i)
    {
        cout << ans[i];
        (i+1 == (int)ans.size()) ? cout << "\n" : cout << " ";
    }
    return 0;  
}

/*
Does order matter? Try sorting
Array bounds, overflow
Reverse the problem, try solving backwards
*/
