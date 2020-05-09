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
    string str;
    cin >> str;

    vector<int> nims; nims.reserve(n);
    int curr = 0, cntA = 0;
    for(auto& ch : str)
    {
        if(ch == 'A')
        {
            ++cntA;
            if(curr > 0)
            {
                nims.push_back(curr);
                curr = 0;
            }
        }
        else
        {
            ++curr;
        }
    }
    nims.push_back(curr);

    int nimsum = 0;
    for(auto& v : nims) nimsum ^= v;

    // Ben first to pick A's
    if(nimsum > 0)
    {
        (cntA % 2 != 0) ? cout << "A\n" : cout << "-1\n";
    }
    else
    {
        (cntA % 2 != 0) ? cout << "B\n" : cout << "-1\n";
    }
    
    return 0;  
}