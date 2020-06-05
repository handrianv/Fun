/* 
    First we compute the sum of digits of every number from 1 - 1e5.
    Now the problem turns into a special case of subset sum, where our (multi)set consists of all number from 1 until n (n = 45 in this problem).

    We can solve this greedily like follow:
    -. Let MX be the largest currently available number in our multiset, and n our target sum. Keep using min(n, MX) from our set until n == 0 or our set is empty.

    Proof:
    We keep using MX until n < MX. We need to prove that when n < MX, there exists a number M in our set such that M == n.
    Since we keep using the largest number from our set, we know we haven't used any number M < MX. Since n < MX, then n is one of those M.
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

const int MAXNUM = 1e5;
int cnt[50];

int SumDigits(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<pi> vec(MAXNUM); // {sum digits, num}
    for(int i = 1; i < MAXNUM; ++i)
    {
        vec.push_back({SumDigits(i), i});
    }
    sort(vec.begin(), vec.end());

    int n;
    cin >> n;
    vector<int> ans; ans.reserve(MAXNUM);

    for(int i = (int)vec.size()-1; i >= 0; --i)
    {
        if(n > vec[i].first)
        {
            n -= vec[i].first;
            ans.push_back(vec[i].second);
        }
        else
        {
            ans.push_back(lower_bound(vec.begin(), vec.end(), pi(n, -1))->second);
            n = 0;
            break;
        }
    }

    if(n > 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans.size() << "\n";
        for(int i = 0; i < (int) ans.size(); ++i)
        {
            cout << ans[i];
            (i+1 == (int)ans.size()) ? cout << "\n" : cout << " ";
        }
    }
    
    return 0;  
}
