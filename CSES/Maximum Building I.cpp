/* 

*/

#include <iostream>
#include <iomanip>
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1005;
char board[MAXN][MAXN];
int top[MAXN][MAXN];

int LargestRectInHistogram(vector<int>& histogram)
{
    int ans = 0;
    histogram.push_back(-1);
    int n = histogram.size();
    stack<int> st; // {index}

    for(int i = 0; i < n; ++i)
    {
        int curr = histogram[i];
        while(!st.empty() && histogram[st.top()] > curr)
        {
            int t = st.top();
            st.pop();
            int width = (st.empty()) ? i : ((i-t) + (t-st.top()) - 1);
            ans = max(ans, histogram[t] * width);
        }
        st.push(i);
    }
    
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> board[i][j];
            if(board[i][j] == '.') top[i][j] = top[i-1][j]; else top[i][j] = i;
        }
    }
    int ans = 0;
    for(int i = n; i > 0; --i)
    {
        vector<int> histogram(m);
        for(int j = 1; j <= m; ++j)
        {
            histogram[j-1] = i-top[i][j];
        }
        ans = max(ans, LargestRectInHistogram(histogram));
    }
    cout << ans << "\n";
    return 0; 
}
