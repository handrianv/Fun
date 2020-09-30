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
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    ll a, b, c;
    ll needA, needB, needC;
    cin >> a >> b >> c >> needA >> needB >> needC;

    ll extraA = max(0LL, needA-a), extraB = max(0LL, needB-b);
    if(extraA + extraB > c)
    {
        cout << "There are no miracles in life\n";
        return 0;
    }

    c -= (extraA + extraB);
    ll remA = (extraA == 0) ? a-needA : 0;
    ll remB = (extraB == 0) ? b-needB : 0;
    (c+remA+remB >= needC) ? cout << "It is a kind of magic\n" : cout << "There are no miracles in life\n";
    return 0;
}
 
/*
 
*/ 