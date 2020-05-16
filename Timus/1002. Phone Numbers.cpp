/* 
    State
    dp[n] = answer for length n

    Transition
    dp[n] = min(dp[n], dp[n-word.length] + 1) for every word

    Complexity O(N * Sum(length(word))). We can speed it up using rolling hash but it's not necessary 
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

const int INVALID = 1e9;
int dp[105];
int ansIdx[105];
string target;
int n;
string wordList[50005], oriList[50005];

inline string Convert(const string& str)
{
     string result = "";
     for(auto ch : str)
     {
         if(ch == 'i' || ch == 'j')  result += '1';
         else if(ch == 'a' || ch == 'b' || ch == 'c') result += '2';
         else if(ch == 'd' || ch == 'e' || ch == 'f') result += '3';
         else if(ch == 'g' || ch == 'h') result += '4';
         else if(ch == 'k' || ch == 'l') result += '5';
         else if(ch == 'm' || ch == 'n') result += '6';
         else if(ch == 'p' || ch == 'r' || ch == 's') result += '7';
         else if(ch == 't' || ch == 'u' || ch == 'v') result += '8';
         else if(ch == 'w' || ch == 'x' || ch == 'y') result += '9';
         else if(ch == 'o' || ch == 'q' || ch == 'z') result += '0';
     }
     return result;
}

void Backtrack(int curr)
{
    if(curr == 0) return;
    Backtrack(curr-wordList[ansIdx[curr]].size());
    cout << oriList[ansIdx[curr]];
    (curr == target.size()) ? cout << "\n" : cout << " ";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> target;

    while(target != "-1")
    {
        cin >> n;

        for(int i = 0; i < n; ++i)
        {
            string str;
            cin >> str;
            wordList[i] = Convert(str);
            oriList[i] = str;
        }

        for(int i = 1; i <= target.size(); ++i)
        {
            dp[i] = INVALID;

            for(int j = 0; j < n; ++j)
            {
                int curr_sz = wordList[j].size();
                if(curr_sz <= i && wordList[j] == target.substr(i-curr_sz, curr_sz) && dp[i-curr_sz] != INVALID)
                {
                    if(dp[i-curr_sz] + 1 < dp[i])
                    {
                        dp[i] = dp[i-curr_sz] + 1;
                        ansIdx[i] = j;
                    }
                }
            }
        }

        if(dp[target.size()] == INVALID) cout << "No solution.\n";
        else Backtrack(target.size());
        cin >> target;
    }
    return 0;
}