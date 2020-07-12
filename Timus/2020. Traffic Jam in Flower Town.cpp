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
#include <bitset>
#include <random>
#include <chrono>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
 
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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    int ptr1 = 0, ptr2 = 0, ans = 0;
    while(ptr1 < n && ptr2 < m)
    {
        if(s1[ptr1] == 'L' && s2[ptr2] != 'L')
        {
            ++ptr2;
        }
        else if(s2[ptr2] == 'L' && s1[ptr1] != 'L')
        {
            ++ptr1;
        }
        else
        {
            ++ptr1; ++ptr2;
        }
        ++ans;
    }
    ans += (n-ptr1); ans += (m-ptr2);
    cout << ans << "\n";
    return 0;
}