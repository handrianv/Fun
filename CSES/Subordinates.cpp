/* 
*/

#include <stdio.h>
#include <bits/stdc++.h>
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 2e5+5;
vector<int> graph[MAXN];
int sz[MAXN];
int n;

void DFS(int curr, int par)
{
    ++sz[curr];
    for(auto neighbor : graph[curr])
    {
        if(neighbor == par) continue;
        DFS(neighbor, curr);
        sz[curr] += sz[neighbor];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 2; i <= n; ++i)
    {
        int num;
        cin >> num;
        graph[num].push_back(i);
    }
    DFS(1, 1);
    for(int i = 1; i <= n; ++i)
    {
        cout << sz[i]-1;
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0;
}   