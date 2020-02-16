/* 
    The graph must be a single strongly connected component.
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1e5+5;
vector<int> graph[MAXN];
int dfsLow[MAXN], dfsNum[MAXN];
bool inStack[MAXN];
stack<int> st;
int n, m, num = 0;

void DFS(int curr)
{
    dfsNum[curr] = dfsLow[curr] = ++num;
    st.push(curr);
    inStack[curr] = true;

    for(auto& neighbor : graph[curr])
    {
        if(dfsNum[neighbor] == 0)
        {
            DFS(neighbor);
            dfsLow[curr] = min(dfsLow[curr], dfsLow[neighbor]);
        }
        else if(inStack[neighbor])
        {
            dfsLow[curr] = min(dfsLow[curr], dfsNum[neighbor]);
        }
    }
    
    if(dfsNum[curr] == dfsLow[curr])
    {
        while(st.top() != curr)
        {
            inStack[st.top()] = false;
            st.pop();
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    DFS(1);
    for(int i = 2; i <= n; ++i)
    {
        if(dfsNum[i] == 0 || dfsNum[i] == dfsLow[i])
        {   cout << "NO\n";
            (dfsNum[i] == 0) ? cout << "1 " << i << "\n" : cout << i << " 1\n";
            return 0; 
        }
    }
    cout << "YES\n";
    return 0; 
}