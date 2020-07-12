/*
    The trick is in the constraint.
    Once the size of the stack exceeds the number of operations left, we can ignore all subsequent copy operation.
    This is because if number of operation < stack size, then the stack can never be popped until empty.
    Which in turn makes copying useless, since we know even with copying we will just operate on the same current stack.
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
    vector<int> vec; vec.reserve(1e6+5);
    while(n--)
    {
        int x;
        cin >> x;
        if(x > 0) vec.push_back(x);
        else if(x < 0)
        {
            cout << vec.back() << "\n";
            vec.pop_back();
        }
        else
        {
            int sz = vec.size();
            if(sz >= n) continue;
            for(int i = 0; i < sz; ++i)
            {
                vec.push_back(vec[i]);
            }
        }
    }
    return 0;
}