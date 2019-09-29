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
vector<int> graph[MAXN];
int dpSub[MAXN], dpSub_2[MAXN];
int dpAll[MAXN], dpAll_2[MAXN];
int n;
 
void GetMax(int temp, int& x, int& y)
{
    if(temp >= x)
    {
        y = x;
        x = temp;
    }
    else if(temp > y)
        y = temp;
}
 
int DPSub(int curr, int par)
{
    for(const auto& child : graph[curr])
    {
        if(child == par) continue;
        int temp = DPSub(child, curr) + 1;
        GetMax(temp, dpSub[curr], dpSub_2[curr]);
    }
    dpAll[curr] = dpSub[curr];
    dpAll_2[curr] = dpSub_2[curr];
    return dpSub[curr];
}
 
void DPAll(int curr, int par)
{
    for(const auto& child : graph[curr])
    {
        if(child == par) continue;
        
        int temp;
        // Best path from parent goes through this child
        if(dpAll[curr] == dpSub[child] + 1)
            temp = dpAll_2[curr] + 1;
        else
            temp = dpAll[curr] + 1;
 
        GetMax(temp, dpAll[child], dpAll_2[child]);
        DPAll(child, curr);
    }
}
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DPSub(1, -1);
    DPAll(1, -1);
    for(int i = 1; i <= n; ++i)
    {
        cout << dpAll[i];
        (i == n) ? cout << "\n" : cout << " ";
    }
    return 0; 
}       