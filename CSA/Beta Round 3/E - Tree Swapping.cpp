/*
    TODO: Revisit proof

    Root the tree and color the root red / blue, then the color of every node is determined.
    If in a subtree we have x wrong red (red that should've been blue) that are still unmatched, and y wrong blue, it's optimal to match min(x, y) within the subtree, and the rest should go up this subtree.
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int MAXN = 1e5+5, INF = 1e9;
vector<int> graph[MAXN];
int color[MAXN]; // {0: red, 1: blue}
int n, ans = 0;

int DFS(int curr, int c, int par)
{
    int wrongRed = 0, wrongBlue = 0;

    for(auto& v : graph[curr])
    {
        if(v == par) continue;
        int temp = DFS(v, c^1, curr);
        if(temp > 0) wrongRed += temp; else wrongBlue += abs(temp);
    }

    ans += (wrongRed + wrongBlue);
    wrongRed += (c == 0 && color[curr] == 1);
    wrongBlue += (c == 1 && color[curr] == 0);
    return (wrongRed >= wrongBlue) ? wrongRed-wrongBlue : -1*(wrongBlue-wrongRed);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        char ch;
        cin >> ch;
        color[i] = (ch == 'B');
    }
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ansAll = INF;
    if(DFS(1, 0, 1) == 0) ansAll = ans;
    ans = 0;
    if(DFS(1, 1, 1) == 0) ansAll = min(ansAll, ans);
    
    if(ansAll == INF) ansAll = -1;
    cout << ansAll << "\n";
    return 0;
}
 
/*
 
*/ 