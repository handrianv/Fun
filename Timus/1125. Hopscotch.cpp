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

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    vector<int> isSquare(5005);
    for(int i = 0; i*i <= 5000; ++i)
    {
        isSquare[i*i] = true;
    }

    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for(auto& v : board)
    {
        for(auto& vv : v)
        {
            cin >> vv;
        }
    }

    vector<vector<int>> vec(m, vector<int>(n));
    for(auto& v : vec)
    {
        for(auto& vv : v)
        {
            cin >> vv;
            (vv % 2 == 0) ? vv = 0 : vv = 1;
        }
    }

    auto GetPar = [&](int row, int cols)
    {
        bool par = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int dr = abs(row-i);
                int dc = abs(cols-j);
                if(isSquare[dr*dr+dc*dc]) // means that center of cell (i, j) is integer amount from cell (row, cols)
                {
                    par ^= vec[i][j];
                }
            }
        }
        return par;
    };

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(GetPar(i, j))
            {
                board[i][j] = ((board[i][j] == 'W') ? 'B' : 'W');
            }
        }
    }

    for(auto& v : board)
    {
        for(auto& vv : v)
        {
            cout << vv;
        }
        cout << "\n";
    }
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/  