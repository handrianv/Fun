/*
    https://acm.timus.ru/problem.aspx?space=1&num=1048
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
#define CeilDiv(a, b) ((a + b - 1) / b)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


void Solve(const int &tc = 1)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    vector<int> ans;
    bool carry = false;
    for(int i = n-1; i >= 0; --i)
    {
        int s = a[i] + b[i] + carry;
        ans.push_back(s % 10);
        carry = (s > 9);
    }
    
    if(carry) ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); ++i)
    {
        cout << ans[i];
        if(i+1 == (int)ans.size()) cout << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(9);

    int tc = 1;
    //cin >> tc;
    for (int i = 1; i <= tc; ++i)
    {
        Solve(i);
    }
    return 0;
}

/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
multiset count IS NOT O(LOG N)!! It's also linear in the number of matches! Costed TLE in systest :(
setprecision for doubles!! Costed me half a day of life!!
*/