/* 
    We can run two DFS:
    -. One on the original graph to check if a node has a victim in its subtree
    -. Another on the reverse graph to check if a node has a victim in its ancestors.
    Then a werewolf is a node that does not satisfy both checks.

    Another alternative solution without having to create reverse graph is as follows:
    -. When a node is a victim, we mark all of its child victim as well.
    -. Run another DFS, and a node is a werewolf if it does not contain any victim in its subtree.
    Why don't we need to check if any ancestor is a victim anymore? If any ancestor is a victim, then this node will already be marked a victim as well in the first step.
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

const int MAXN = 1005;
vector<vector<int>> graph1(MAXN), graph2(MAXN);
bool isVictim[MAXN]; int val1[MAXN], val2[MAXN];
int n;

bool DFS(const vector<vector<int>>& graph, int* val, int curr)
{
    if(val[curr] != -1) return val[curr];
    if(isVictim[curr]) return (val[curr] = 1);
    
    bool hasVictim = false;
    for(auto& child : graph[curr])
    {
        hasVictim |= DFS(graph, val, child);
    }
    return (val[curr] = hasVictim);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    string str;
    cin.get(); getline(cin, str);
    while(str[0] != 'B')
    {
        stringstream ss(str);
        int child, parent;
        ss >> child >> parent;
        graph1[parent].push_back(child);
        graph2[child].push_back(parent);
        getline(cin, str);
    }

    int victim;
    while(cin >> victim)
    {
        isVictim[victim] = true;
    }

    memset(val1, -1, sizeof(val1)); memset(val2, -1, sizeof(val2));
    for(int i = 1; i <= n; ++i)
    {
        if(val1[i] == -1) DFS(graph1, val1, i);
        if(val2[i] == -1) DFS(graph2, val2, i);
    }

    vector<int> ans;
    for(int i = 1; i <= n; ++i)
    {
        if(!val1[i] && !val2[i]) ans.push_back(i);
    }
    
    if(ans.empty()) ans.push_back(0);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < (int)ans.size(); ++i)
    {
        cout << ans[i];
        (i+1 == (int)ans.size()) ? cout << "\n" : cout << " ";
    }
    return 0;
}

// Alternative solution without reverse graph

// void DFS2(int curr)
// {
//     isVictim[curr] = true;
//     for(auto& child : graph1[curr])
//     {
//         if(!isVictim[child]) DFS2(child);
//     }
// }

// bool DFS3(int curr, vector<int>& ans)
// {
//     if(isVictim[curr]) return (val1[curr] = 1);
//     if(val1[curr] != -1) return val1[curr];

//     bool hasVictim = false;
//     for(auto& child : graph1[curr])
//     {
//         hasVictim |= DFS3(child, ans);
//     }

//     //cout << "hasVictim " << curr << " is " << hasVictim << "\n";
//     if(!hasVictim) ans.push_back(curr);
//     return (val1[curr] = hasVictim);
// }

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
//     cin >> n;
//     string str;
//     cin.get(); getline(cin, str);
//     while(str[0] != 'B')
//     {
//         stringstream ss(str);
//         int child, parent;
//         ss >> child >> parent;
//         graph1[parent].push_back(child);
//         graph2[child].push_back(parent);
//         getline(cin, str);
//     }

//     int victim;
//     while(cin >> victim)
//     {
//         isVictim[victim] = true;
//         DFS2(victim);
//     }

//     vector<int> ans;
//     memset(val1, -1, sizeof(val1));
//     for(int i = 1; i <= n; ++i)
//     {
//         if(val1[i] == -1) DFS3(i, ans);
//     }    
    
//     if(ans.empty()) ans.push_back(0);
//     sort(ans.begin(), ans.end());
//     for(int i = 0; i < (int)ans.size(); ++i)
//     {
//         cout << ans[i];
//         (i+1 == (int)ans.size()) ? cout << "\n" : cout << " ";
//     }
//     return 0;
// }
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/