/* 
    Observe that a fold doesn't change the sum of layers. So no matter the sequence of folds, as long as the end result is 1 cm long it'll have n layers.
    So now the problem turns into: 
    We have a number n. In each move we can reduce it by any integer up to floor(n / 2) (because at most we can fold half the paper). Find minimum number of moves to reduce it to 1.
    It's easy to see that we can do it greedily by folding as much as possible in each step.

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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n; 
    cin >> n;

    vector<int> ans;
    while(n > 1)
    {
        int half = n / 2;
        n -= half;
        ans.push_back(half);
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); ++i)
    {
        cout << ans[i];
        (i + 1 == (int)ans.size()) ? cout << "\n" : cout << " ";
    }
    return 0;  
}
