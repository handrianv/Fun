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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 505;
const ll INF = 1e18;
ll adjMat[MAXN][MAXN];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) if(i != j) adjMat[i][j] = INF;
    for(int i = 0; i < m; ++i)
    {
        int a, b; ll c;
        cin >> a >> b >> c;
        adjMat[a][b] = adjMat[b][a] = min(adjMat[a][b], c);
    }
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
            }
        }
    }

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        (adjMat[a][b] == INF) ? cout << "-1\n" : cout << adjMat[a][b] << "\n";
    }
    return 0; 
}           