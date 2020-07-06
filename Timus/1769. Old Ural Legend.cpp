/*
    The length of digit of the answer is at most 5, because we have 10^5 numbers but < 10^5 substrings of that length.
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

int Check(const string& str, int len)
{
    int maxNum = 1;
    for(int i = 0; i < len; ++i) maxNum *= 10;
    vector<char> has(maxNum);

    int curr = 0;
    for(int i = 0; i < len; ++i)
    {
        curr *= 10;
        curr += (str[i]-'0');
    }

    has[curr] = true;
    for(int i = 1; i+len-1 < (int)str.size(); ++i)
    {
        curr -= ((str[i-1]-'0') * maxNum / 10);
        curr *= 10;
        curr += (str[i+len-1]-'0');
        has[curr] = true;
    }

    for(int i = maxNum/10; i < maxNum; ++i)
    {
        if(!has[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    cin >> str;
    for(int len = 1; ; ++len)
    {
        int ans = Check(str, len);
        if(ans != -1)
        {
            cout << ans << "\n";
            break;
        }
    }
    return 0;
}
