/*
    Recall an important property of prufer sequence:
    (1) For each node v, it appears d(v)-1 times in the sequence, where d(v) is its degree
    So given the sequence, we immediately know which number are leafs in the original tree; the numbers that do not appear in the sequence.

    Now we just do the reverse of what the algorithm to turn tree into prufer code does. To turn a tree into prufer code:
    -. Get leaf with smallest index
    -. Remove it, and write its neighbor number to the array. This neighbor might or might not become a new leaf, depending on its remaining degree.

    We know the initial leafs, let's get the one with smallest index, and attach it to the first number in the array.
    This number might or might not become a new leaf, we need to check its degree, how? Just keep track of its frequency. Remember that by (1), if a number has frequency 0 in the sequence, it's now a leaf.
    We repeat this process until we have the whole tree
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
    vector<int> vec, cnt(8000);
    int x;
    while(cin >> x)
    {
        vec.push_back(x);
        ++cnt[x];
    }

    int n = vec.size() + 1;
    set<int> leafs;
    for(int i = 1; i <= n; ++i) leafs.insert(i);
    for(auto& v : vec) if(leafs.count(v)) leafs.erase(v);

    vector<vector<int>> graph(n+5);
    for(auto& v : vec)
    {
        int leaf = *(leafs.begin());
        leafs.erase(leafs.begin());
        graph[v].push_back(leaf);
        graph[leaf].push_back(v);
        --cnt[v];
        if(!cnt[v])
        {
            leafs.insert(v);
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        cout << i << ": ";
        sort(graph[i].begin(), graph[i].end());
        for(int j = 0; j < (int)graph[i].size(); ++j)
        {
            cout << graph[i][j];
            (j+1 == (int)graph[i].size()) ? cout << "\n" : cout << " ";
        }
    }
    return 0;
}

/*

*/  