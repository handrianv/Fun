/*

*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; 

const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int val[MAXN], start[MAXN], finish[MAXN];
int n, q, counter;
ll pathSum[MAXN], fenwick[MAXN];

void Update(int idx, int val)
{
    while(idx <= n)
    {
        fenwick[idx] += val;
        idx += LSOne(idx);
    }
}

ll Query(int idx)
{
    ll ans = 0;
    while(idx > 0)
    {
        ans += fenwick[idx];
        idx -= LSOne(idx);
    }
    return ans;
}

void DFS(int curr, int par)
{
    start[curr] = ++counter;
    pathSum[curr] = val[curr] + pathSum[par];

    for(auto& neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        DFS(neighbor, curr);
    }
    finish[curr] = counter;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> val[i];
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1, 1);

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int s, x;
            cin >> s >> x;
            Update(start[s], x-val[s]);
            Update(finish[s] + 1, -(x-val[s]));
            val[s] = x;
        }
        else
        {
            int s;
            cin >> s;
            cout << pathSum[s] + Query(start[s]) << "\n";
        } 
    }
    return 0; 
}