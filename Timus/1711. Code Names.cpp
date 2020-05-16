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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<vector<string>> vec(n+5, vector<string>(3));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cin >> vec[i][j];
        }
    }

    vector<string> res(n);
    string prev = "^"; bool can = true;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        string curr = "{";
        for(auto& word : vec[x])
        {
            if(word > prev) curr = min(curr, word);
        }
        if(curr == "{") can = false;
        res[i] = prev = curr;
        //cout << "curr is " << curr << endl;
    }
    
    if(!can) cout << "IMPOSSIBLE\n";
    else
    {
        for(auto& r : res) cout << r << "\n";
    }
    
    return 0; 
}