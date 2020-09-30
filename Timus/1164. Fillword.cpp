/*
    Just a problem with ambiguous statement.
    Read the problem description carefully, it's already guaranteed that:
    -. Each word will appear in the grid.
    -. A cell can only be part of one word.
    And our task is only to print the (sorted) set of unused letters. This means we can just keep track of frequency of each character -_-
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
    int n, m, p;
    cin >> n >> m >> p;
    map<char, int> freq;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            char ch;
            cin >> ch;
            ++freq[ch];
        }
    }
    while(p--)
    {
        string str;
        cin >> str;
        for(auto& ch : str) --freq[ch];
    }

    string ans = "";
    for(auto& kv : freq)
    {
        while(kv.second--)
        {
            ans += kv.first;
        }
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 