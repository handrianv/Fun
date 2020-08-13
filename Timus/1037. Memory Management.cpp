/*
    Suppose we have an array with N elements and in each index store its "expiration time", which is the time T this block becomes free.
    Then the problem is asking to support these 2 operations:
    -. Given time T, find leftmost (in other word, smallest) index with expiration time >= T
    -. Update expiration time of a single index
    Both of which are quite straightforward application of RMQ segment tree, with a slight modification of the query function.
    In normal segment tree, we query left & right subtree and get the minimum. In this problem, if the left subtree has value < T, we can just go left and ignore the right subtree
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

const int MAXN = 3e4+1;
int expTime[MAXN]; // Expiration time. Expired == !allocated
int segtree[4*MAXN]; // Store min expiration time. 

// Get leftmost expired
int Update(const int& curr, const int& left, const int& right, const int& t)
{
    if(left == right)
    {
        expTime[left] = t+600;
        segtree[curr] = expTime[left];
        return left;
    }
    int mid = left + (right-left) / 2;
    int ans;
    if(segtree[2*curr] <= t) ans = Update(curr*2, left, mid, t);
    else ans = Update(curr*2+1, mid+1, right, t);
    segtree[curr] = min(segtree[curr*2], segtree[curr*2+1]);
    return ans;
}

// Update expTime single block
void Update2(const int& curr, const int& left, const int& right, const int& t, const int& blockNum)
{
    if(left == right)
    {
        expTime[left] = t + 600;
        segtree[curr] = expTime[left];
        return;
    }
    int mid = left + (right-left) / 2;
    if(blockNum <= mid) Update2(curr*2, left, mid, t, blockNum);
    else Update2(curr*2+1, mid+1, right, t, blockNum);
    segtree[curr] = min(segtree[curr*2], segtree[curr*2+1]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    while(cin >> t)
    {
        char type;
        cin >> type;
        if(type == '+')
        {
            int ans = Update(1, 1, MAXN, t);
            cout << ans << "\n";
        }
        else
        {
            int blockNum;
            cin >> blockNum;
            if(expTime[blockNum] > t)
            {
                Update2(1, 1, MAXN, t, blockNum);
                cout << "+\n";
            }
            else
            {
                cout << "-\n";
            }
        }
    }
    return 0;
}

/*

*/  