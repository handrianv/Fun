/*
    dp[n][i] = minimum cut needed for substring with index 0...n, if the last cut is before index i
    dp[n][i] = min(dp[n][i], dp[i-1][k]) for every k that can cut substring 0..i-1.
    For index i to be valid cut, the substring i...n must be a palindrome.
    
    To check quickly if a substring is a palindrome we do another dp
    isPalindrome[i][j] = if substring i..j is a palindrome
    isPalindrome[i][j] = (string[i] == string[j]) && (isPalindrome[i+1][j-1])
    
    EXTRA: There is a faster solution using palindromic tree (http://codeforces.com/blog/entry/19193)
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
    string str;
    cin >> str;
    int n = str.size();
    vector<vector<char>> isPalindrome(n, vector<char>(n));
    for(int len = 1; len <= n; ++len)
    {
        for(int left = 0; left+len-1 < n; ++left)
        {
            int right = left+len-1;
            isPalindrome[left][right] = (str[left] == str[right]);
            if(left+1 < right-1)
            {
                isPalindrome[left][right] &= isPalindrome[left+1][right-1];
            }
        }
    }

    vector<int> dp(n, 1e9), len(n);
    for(int i = 0; i < n; ++i)
    {
        if(isPalindrome[0][i])
        {
            dp[i] = 1;
            len[i] = i+1;
            continue;
        }

        for(int j = i; j > 0; --j)
        {
            if(isPalindrome[j][i] && dp[j-1] + 1 < dp[i])
            {
                dp[i] = dp[j-1] + 1;
                len[i] = i-j+1;
            }
        }
    }

    cout << dp[n-1] << "\n";

    // Backtrack
    vector<string> ans; ans.reserve(dp[n-1]+5);
    int curr = n-1;
    while(curr >= 0)
    {
        ans.push_back(str.substr(curr-len[curr]+1, len[curr]));
        curr -= len[curr];
    }
    for(int i = ans.size()-1; i >= 0; --i)
    {
        cout << ans[i];
        (i == 0) ? cout << "\n" : cout << " ";
    }
    return 0;
}
 
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/