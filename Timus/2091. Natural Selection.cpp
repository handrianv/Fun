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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
        }
    }

    pi ans; int currMx = 1e9;
    for(int c1 = 0; c1 < m; ++c1)
    {
        for(int c2 = c1+1; c2 < m; ++c2)
        {
            vector<int> res(4);
            for(int i = 0; i < n; ++i)
            {
                if(vec[i][c1] && vec[i][c2]) ++res[0];
                else if(vec[i][c1] && !vec[i][c2]) ++res[1];
                else if(!vec[i][c1] && vec[i][c2]) ++res[2];
                else ++res[3];
            }

            int mx = *max_element(res.begin(), res.end());
            if(mx < currMx)
            {
                ans = {c1+1, c2+1};
                currMx = mx;
            }
        }
    }
    
    cout << currMx << "\n" << ans.first << " " << ans.second << "\n";
    return 0;  
}