/* 
    Standard digit DP.
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

int pow10[10];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    pow10[0] = 1;
    for(int i = 1; i < 10; ++i) pow10[i] = 10 * pow10[i-1];

    string str;
    cin >> str;
    int n = str.size();
    vector<int> cnt(10);

    // Prefix: current character, Suffix: everything to the right
    for(int i = 0; i < n; ++i)
    {
        int limit = str[i] - '0'; // Max possible prefix
        int suffixLen = n-i-1;
        int suffixCnt = pow10[suffixLen] * suffixLen / 10; // How many times digit d appears for all possible suffix

        // Assuming prefix < limit
        for(int d = 0; d < 10; ++d)
        {
            cnt[d] += (limit * suffixCnt); // How many times digit d appears in suffix for every prefix

            // When prefix is zero, discard leading zero of suffix
            if(i == 0 && d == 0)
            {
                for(int p = 1; p <= suffixLen; ++p)
                {
                    cnt[0] -= (pow10[suffixLen-p]);
                }
            }

            if(d < limit && !(i == 0 && d == 0)) // Don't cout leading zero appearance as prefix.
            {
                cnt[d] += pow10[suffixLen]; // How many times digit d appears in prefix for every suffix
            }
        }

        // When prefix == limit
        cnt[limit] += ((i+1 == n) ? 1 : stoi(str.substr(i+1, suffixLen)) + 1); // How many times appear as prefix. Plus 1 because suffix starts from zero.
    }

    for(int d = 0; d < 10; ++d)
    {
        cout << cnt[d] << "\n";
    }
    return 0;
}

/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/

/*
-- OLD SOLUTION --
    dp[len][i] = how many times digit i occurs from 1 until substring of length len.
    E.g: Number is 545278, then dp[4][5] denotes how many times digit 5 occurs from 1-5452.
    To count dp[len][i] we can separate it into two parts:
    -. How many times digit i occurs as the last digit.
       Then for every prefix from 0-substr(len-1), we can simply have i as the last digit.
       Using above example, to compute dp[4][5] of 545278 where 5 is the last digit, we can simply append 5 to every prefix from 0-545.
       So we have dp[len][i] += (substr(len-1) + 1).
       But we overcounted some things. That is, for prefix exactly equal to substr(len-1), appending i as the last digit might not be valid.
       Using above example again, appending 5 to 545 is not allowed because the largest prefix of length 4 is only 5452.
       To exclude this is easy, we simply check if last digit of substr(len) < i, if true, we decrement dp[len][i] by one
    -. How many times digit i occurs as not-last-digit position.
       The logic is similar. For every prefix that contains digit i, we can simply append 0-9 at the end.
       So dp[len][i] += (10 * dp[len-1][i]).
       Again we overcounted some things. For prefix equal to substr(len-1), appending a digit larger that last digit of substr(len) is not allowed.
       So we can simply count number of digit i in substr(len-1), and subtract every combination with non-valid last digit.
       So dp[len][i] -= (cnt * (9-last)), where cnt is number of digit i in substr(len-1), and last is last digit of substr(len)
    Notice that above algorithms count leading zeros as valid number, so zeros need a bit of a special handling in the end. Look at code for more clarity

#include <stdio.h>
#include <bits/stdc++.h>
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
typedef pair<int, string> ps;
typedef pair<char, int> pc;
typedef pair<pi, int> pii;
typedef pair<double, double> pd;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;
typedef pair<ull, int> puli;

typedef
tree<
  string,
  null_type,
  less<string>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_multiset;

int dp[15][10];
string str, currPrefix;

int StringToNum()
{
    int num = 0, mult = 1;
    for(int i = currPrefix.size()-1; i >= 0; --i)
    {
        num += (mult*(currPrefix[i]-'0'));
        mult *= 10;
    }
    return num;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> str;
    int extraZero = 0;
    int mult = 1;

    for(int len = 1; len <= str.size(); ++len)
    {
        for(int i = 0; i <= 9; ++i)
        {
            dp[len][i] = 10*dp[len-1][i];

            int cnt  = 0;
            for(auto ch : currPrefix)
            {
                if((ch-'0') == i) ++cnt;
            }
            int currDigit = str[len-1] - '0';
            dp[len][i] -= (cnt * (9-currDigit));

            dp[len][i] += (StringToNum()+1);
            if(i > currDigit) --dp[len][i];
        }

        currPrefix += str[len-1];
        extraZero += mult;
        mult *= 10;
    }

    dp[str.size()][0] -= extraZero;

    for(int i = 0 ; i <= 9; ++i)
    {
        cout << dp[str.size()][i] << "\n";
    }
    return 0;
}
/*