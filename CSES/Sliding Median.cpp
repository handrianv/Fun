/*
    This is a slight modification of the classic "running median" problem. If you can solve the classic version, this one should be straightforward.
    Or we can also cheese this using order statistic.
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
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(auto& v : vec)
    {
        cin >> v;
    }

    multiset<int> left, right;
    auto Rebalance = [&]()
    {
        if(abs(left.size() - right.size() < 2)) return;
        if(left.size() > right.size())
        {
            right.insert(*left.rbegin());
            left.erase(--left.end());
        }
        else
        {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    };

    auto Insert = [&](int y)
    {
        if(left.empty() || y < *left.rbegin())
        {
            left.insert(y);
        }
        else
        {
            right.insert(y);
        }
        Rebalance();
    };
    
    auto Erase = [&](int idx)
    {
        int y = vec[idx];
        if(left.count(y))
        {
            left.erase(left.find(y));
        }
        else
        {
            right.erase(right.find(y));
        }
        Rebalance();
    };

    auto Answer = [&]()
    {
        if(k % 2 == 0) return *left.rbegin();
        if(left.size() > right.size()) return *left.rbegin();
        else return *right.begin();
    };

    for(int i = 0; i < n; ++i)
    {
        Insert(vec[i]);
        if(i >= k-1)
        {
            if(i >= k)
            {
                Erase(i-k);
            }
            cout << Answer() << " \n"[i+1 == n];
        }
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