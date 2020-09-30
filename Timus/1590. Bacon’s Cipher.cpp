/*
    Classic problem with multiple O(N^2) solutions, although hashing is too slow because we need to keep 25 mil hash.
    The simplest approach is probably Z-function: https://cp-algorithms.com/string/z-function.html. But KMP would work as well.
    For even faster solution we can use more advanced stuff like suffix tree.
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

int Z(const string& str)
{
    int n = str.size();
    vector<int> z(n);
    int x = 0, y = 0, mxz = 0;
    for(int i = 1; i < n; ++i)
    {
        z[i] = max(0, min(z[i-x], y-i+1));
        while(i+z[i] < n && str[z[i]] == str[i+z[i]])
        {
            x = i; y = i+z[i]; ++z[i];
        }
        mxz = max(mxz, z[i]);
    }
    return n-mxz;
} 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    cin >> str;

    string t = "";
    int ans = 0;
    for(auto& ch : str)
    {
        t += ch;
        string rt = t; reverse(rt.begin(), rt.end());
        ans += Z(rt);
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 