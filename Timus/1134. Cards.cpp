/*
    Order doesn't matter. An invalid sequence of card, after reordering, is still invalid.
    Sort the input. Label the cards with the lower numbered face. E.g. Card 0 is (0-1), Card 1 is (1-2), etc..
    Now every number x except 0 and n belong to two cards, card x and card x-1
    Always use the lower numbered card if possible.
    If card x-1 is not used yet, by using card x-1 we also lost one chance to use number x-2. But since input is sorted, x-2 will never appear again.
    On the other hand, if we use card x, we lost one chance to use number x+1, but x+1 may appear again in the future.
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
    int n, m;
    cin >> n >> m;
    vector<int> vec(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vector<char> taken(n+5);
    bool can = true;
    for(auto& v : vec)
    {
        if(v == 0 && taken[0]) can = false;
        else if(v == n && taken[n-1]) can = false;
        else if(taken[v-1] && taken[v]) can = false;
        if(!can) break;
        
        if(v == 0 || taken[v-1]) taken[v] = true;
        else taken[v-1] = true;
    }
    (can) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}

/*

*/  