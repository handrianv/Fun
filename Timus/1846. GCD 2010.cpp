/*
    Computing gcd after addition of new element is straightforward. Deleting non-unique element doesn't change the gcd.
    So we only need to concern ourselves with deletion of unique element.
    One way to do it is using segment tree: Keep track of first index of each number and its frequency. When frequency changes to 1 or 0, update accordingly.
    There are solutions that runs in 0.031s, Maybe by using iterative segment tree?
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

const int MAXN = 1e5+5;
int segtree[4*MAXN];

void Update(const int& curr, const int& left, const int& right, const int& pos, const int& num)
{
    if(left == right)
    {
        segtree[curr] = num;
        return;
    }
    int mid = left + (right-left) / 2;
    if(pos <= mid) Update(curr*2, left, mid, pos, num);
    else Update(curr*2+1, mid+1, right, pos, num);
    segtree[curr] = __gcd(segtree[curr*2], segtree[curr*2+1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int q;
    cin >> q;

    map<int, int> freq, pos;
    int sz = 0, ans = 0; 
    while(q--)
    {
        char type; int x;
        cin >> type >> x;
        if(type == '+')
        {
            ans = __gcd(ans, x);
            ++freq[x];
            if(freq[x] == 1)
            {
                pos[x] = (sz++);
                Update(1, 0, MAXN, sz-1, x);
            }
        }   
        else
        {
            --freq[x];
            if(freq[x] == 0)
            {
                Update(1, 0, MAXN, pos[x], 0);
                ans = segtree[1];
            }
        }
        cout << ((ans == 0) ? 1 : ans) << "\n";
    }
    return 0;
}
