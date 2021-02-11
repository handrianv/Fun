/*
    We want a structure that supports fast deletion on arbitrary positions. A linked-list is suitable.
    A straightforward way is to use the built-in list. Or we can also implement this with array by storing next idx of every element.
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
 
#define LSOne(S) (S & (-S))
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
    int n;
    cin >> n;

    list<int> li(n);
    iota(li.begin(), li.end(), 1);

    auto iter = li.begin();
    ++iter;
    while(li.size() > 1)
    {
        cout << (*iter) << " ";
        iter = li.erase(iter);
        if(iter == li.end()) iter = li.begin();
        ++iter;
        if(iter == li.end()) iter = li.begin();
    }
    cout << *li.begin() << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
setprecision for doubles!! Costed me half a day of life!!
*/  