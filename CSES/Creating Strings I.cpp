/* 
    Easy way (c++): use next_permutation
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
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    cin >> str;
    int n = str.size();
    sort(str.begin(), str.end());
    vector<string> res;
    res.reserve(40400);

    while(true)
    {
        res.push_back(str);
        int swapWith = -1;
        for(int i = n-2; i >= 0; --i)
        {
            if(str[i] < str[i+1])
            {
                swapWith = i;
                break;
            }
        }

        if(swapWith == -1) break;

        int swapWith2 = -1;
        for(int i = n-1; i > swapWith; --i)
        {
            if(str[i] > str[swapWith])
            {
                swapWith2 = i;
                break;
            }
        }
        swap(str[swapWith], str[swapWith2]);
        sort(str.begin()+swapWith+1, str.end());
    }
    cout << res.size() << "\n";
    for(auto& r : res) cout << r << "\n";
    return 0; 
}