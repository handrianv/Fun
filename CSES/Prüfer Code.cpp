/* 
    Property of prufer code: Each node i appears (deg(i) - 1) times in the sequence
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


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n-2), deg(n+5, 1);
    for(int i = 0; i < n-2; ++i)
    {
        cin >> vec[i];
        ++deg[vec[i]];
    }

    set<int> leafs;
    for(int i = 1; i <= n; ++i)
    {
        if(deg[i] == 1) leafs.insert(i);
    }

    vector<pi> edges;
    for(const auto& node : vec)
    {
        int curr = *leafs.begin();
        leafs.erase(leafs.begin());
        edges.push_back({curr, node});
        --deg[node];
        if(deg[node] == 1) leafs.insert(node);
    }
    edges.push_back({*leafs.begin(), *(++leafs.begin())});

    for(const auto& edge : edges)
    {
        cout << edge.first << " " << edge.second << "\n";
    }
    return 0; 
}       