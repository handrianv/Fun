/*
    What a delightfully confusing problem statement :)
    See the discussion thread for a good explanation of what the heck this problem means
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

int h, w;

bool Valid(int r, int c)
{
    return min(r, c) >= 0 && r < h && c < w;
}

int Get(const vector<vector<int>>& board, int i, int j)
{
    for(int d = 1; d < 6; ++d)
    {
        int sum = 0;
        for(int dr = -d; dr <= d; ++dr)
        {
            vector<int> dcs = {d-abs(dr), (d-abs(dr)) * -1};
            for(auto& dc : dcs)
            {
                if(Valid(i+dr, j+dc))
                {
                    sum |= board[i+dr][j+dc];
                }
            }
        }
        if(sum > 0) return sum;
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> h >> w;
    vector<vector<int>> board(h, vector<int>(w));
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> ans(h, vector<int>(w));
    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            ans[i][j] = (board[i][j] > 0) ? -1 : Get(board, i, j);
        }
    }

    for(int i = 0; i < h; ++i)
    {
        for(int j = 0; j < w; ++j)
        {
            cout << ans[i][j];
            (j+1 == w) ? cout << "\n" : cout << " ";
        }
    }
    return 0;
}
 
/*
 
*/  