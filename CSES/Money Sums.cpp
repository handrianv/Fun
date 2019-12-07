/*
    dp[i][j] = is it possible to make sum j with first i coins
*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    } 

    vector<int> dp(100*1000+5);
    int sum = 0;
    dp[0] = true;
    for(int i = 0; i < n; ++i)
    {
        sum += coins[i];
        for(int j = sum; j >= coins[i]; --j)
        {
            dp[j] |= dp[j-coins[i]];
        }
    }
    
    vector<int> ans;
    for(int i = 1; i <= sum; ++i) if(dp[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        (i+1 == ans.size()) ? cout << "\n" : cout << " ";
    }
    return 0; 
}