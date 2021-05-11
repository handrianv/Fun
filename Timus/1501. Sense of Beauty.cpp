/*
    There might be some kind of greedy solution to this, but since N is small, we might as well just go with DP.
    Let the red card have value +1 and black card -1. We start with sum 0, and each time we take out a card its value is added to our sum.
    We cannot take 2 of the same colors in a row, so we need our sum to stay within the interval [-1, 1]. Then we can simulate the process with DP.
    
    State
    dp[n][m][k] = can we finish the process if the size of the first stack is n, size of second stack is m, and our current sum is k.
    
    Transition
    dp[n][m][k] = dp[n-1][m][k(+-)1] || dp[n][m-1][k(+-)1], where each choice represents taking a card from the first / second stack, and (+-1) depends
                  on the color of the card we take.
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
 
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1005;
int dp[MAXN][MAXN][3]; // To avoid negative index, we map the sum [-1, 1] to [0, 2] by adding +1.

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    memset(dp, -1, sizeof(dp));
    dp[0][0][1] = 1;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            for(int target = -1; target <= 1; ++target)
            {
                if(i > 0)
                {
                    int curr = (s1[i-1] == '0') ? -1 : 1;
                    int prev = target-curr;
                    if(prev >= -1 && prev <= 1 && dp[i-1][j][prev+1] != -1)
                    {
                        dp[i][j][target+1] = 1;
                    } 
                }
                if(j > 0)
                {
                    int curr = (s2[j-1] == '0') ? -1 : 1;
                    int prev = target - curr;
                    if(prev >= -1 && prev <= 1 && dp[i][j-1][prev + 1] != -1)
                    {
                        dp[i][j][target+1] = 2;
                    }
                }
            }
        }
    }
    
    if(dp[n][n][1] == -1)
    {
        cout << "Impossible\n";
        return 0;
    }

    string ans = "";
    int sz1 = n, sz2 = n, sum = 1;
    while(sz1 > 0 || sz2 > 0)
    {
        ans += (dp[sz1][sz2][sum] == 1 ? '1' : '2');
        if(dp[sz1][sz2][sum] == 1)
        {
            int curr = (s1[sz1-1] == '0') ? -1 : 1;
            sum -= curr;
            --sz1;
        }
        else
        {
            int curr = (s2[sz2-1] == '0') ? -1 : 1;
            sum -= curr;
            --sz2;
        }
        
    }
    cout << ans << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/  