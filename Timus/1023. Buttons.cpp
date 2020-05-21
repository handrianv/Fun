/* 
    A classic variant of nim called subtraction game. https://en.wikipedia.org/wiki/Nim#The_subtraction_game_S(1,_2,_._._.,_k)
    We need to find L such that K % (L+1) == 0. Beware that the problem asks for L >= 2.
    Note that there is always an answer, because L = K-1 will always guarantee victory.
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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int k;
    cin >> k;
    int ans = k;
    for(int i = 2; i*i <= k; ++i)
    {
        if(k % i == 0)
        {
            if(i > 2) ans = min(ans, i);
            if(k/i > 2) ans = min(ans, k/i);
        }
    }
    cout << (ans-1) << "\n";
    return 0;  
}