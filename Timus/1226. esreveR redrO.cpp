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

const int SZ = 260;
char str[SZ];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    while(fgets(str, SZ, stdin) != NULL)
    {
        int len = strlen(str);
        string res = "";
        int start = 0;

        for(int i = 0; i < len; ++i)
        {
            if(!isalpha(str[i]))
            {
                reverse(res.begin()+start, res.end());
                start = i+1;
            }
            res += str[i];
        }
        if(start < len) reverse(res.begin()+start, res.end());
        cout << res;
    }
    return 0;
}
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/