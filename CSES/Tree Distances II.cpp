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
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 2e5+5;
vector<ll> graph[MAXN];
ll dpSub[MAXN], subSz[MAXN], dpAll[MAXN];
int n;

void DPSub(int curr, int par)
{
    subSz[curr] = 1;
    for(const auto& child : graph[curr])
    {
        if(child == par) continue;
        DPSub(child, curr);
        dpSub[curr] += (dpSub[child] + subSz[child]);
        subSz[curr] += subSz[child];
    }
}

void DPAll(int curr, int par)
{
    for(const auto& child : graph[curr])
    {
        if(child == par) continue;
        dpAll[child] = dpAll[curr] + n - 2*subSz[child];
        DPAll(child, curr);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n- 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DPSub(1, -1);
    dpAll[1] = dpSub[1];
    DPAll(1, -1);
    for(int i = 1; i <= n; ++i)
    {
        cout << dpAll[i];
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0; 
}       