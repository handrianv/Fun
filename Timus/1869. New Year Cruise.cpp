/*
    Just implement what is written.
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
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }

    int mx = 0, sum = 0;
    for(int i = 0; i < n; ++i)
    {
        // People that start on this station
        for(int j = i+1; j < n; ++j) sum += mat[i][j];
        // People that drop off on this station
        for(int j = i-1; j >= 0; --j) sum -= mat[j][i];
        mx = max(mx, sum);
    }

    sum = 0;
    for(int i = n-1; i >= 0; --i)
    {
        // People that start on this station
        for(int j = i-1; j >= 0; --j) sum += mat[i][j];
        // People that drop off on this station
        for(int j = i+1; j < n; ++j) sum -= mat[j][i];
        mx = max(mx, sum);
    }

    cout << CeilDiv(mx, 36) << "\n";
    return 0;
}
 
/*
 
*/ 