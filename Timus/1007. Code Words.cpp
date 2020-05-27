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
typedef pair<bool, int> pbi;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    ++n;
    string str;

    while(cin >> str)
    {
        int sz = str.size(), rem = 0;
        vector<int> cnt(sz+1); // Suffix sum
        for(int i = sz-1; i >= 0; --i)
        {
            cnt[i] = (str[i] == '1');
            (rem += cnt[i] * (i+1)) %= n;  
            cnt[i] += cnt[i+1]; 
        }

        if(sz == n-1)
        {
            if(rem > 0) str[rem-1] = '0';
        }
        else if(sz < n-1)
        {
            for(int i = 0; i <= sz; ++i)
            {
                int newRem0 = (rem + cnt[i]) % n;
                if(newRem0 == 0)
                {
                    str.insert(i, "0");
                    break;
                }

                int newRem1 = (newRem0 + (i+1)) % n;
                if(newRem1 == 0)
                {
                    str.insert(i, "1");
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < sz; ++i)
            {
                int newRem = (rem - (str[i] == '1') * (i+1) - cnt[i+1]);
                (newRem += n) %= n;
                if(newRem == 0)
                {
                    str.erase(i, 1);
                    break;
                }
            }
        }

        cout << str << "\n";
    }
    return 0;  
}