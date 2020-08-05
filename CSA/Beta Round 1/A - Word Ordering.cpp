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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string order;
    cin >> order;
    map<char, int> idxOf;
    for(int i = 0; i < (int)order.size(); ++i)
    {
        idxOf[order[i]] = i;
        idxOf[toupper(order[i])] = i + order.size();
    }

    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), [&](const string& s1, const string& s2)
    {
        int sz = min(s1.size(), s2.size());
        for(int i = 0; i < sz; ++i)
        {
            char ch1 = s1[i], ch2 = s2[i];
            if(idxOf[ch1] < idxOf[ch2]) return true;
            else if(idxOf[ch2] < idxOf[ch1]) return false;
        }
        return s1.size() < s2.size();
    });
    
    for(auto& v : vec)
    {
        cout << v << "\n";
    }
    return 0;
}

/*

*/