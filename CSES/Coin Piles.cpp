/* 

*/

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

int can[100][100];

bool DP(int x, int y)
{
    if(x < 0 || y < 0) return false;
    if(x == 0 && y == 0) return true;
    if(can[x][y] != -1) return can[x][y];
    can[x][y] = false;
    can[x][y] |= DP(x-1, y-2);
    can[x][y] |= DP(x-2, y-1);
    return can[x][y];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int d = b-a;
        a -= d;
        b -= 2*d;
        if( (a >= 0 && a % 3 == 0) && (b >= 0 && b % 3 == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0; 
}
