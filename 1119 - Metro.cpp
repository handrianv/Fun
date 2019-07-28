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

const int MAXN = 1005;
const double DIAGONAL = 100.0 * sqrt(2.0);
bool can[MAXN][MAXN];
double dist[MAXN][MAXN];
int m, n, k;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> m >> n >> k;
    while(k--)
    {
        int i, j;
        cin >> j >> i;
        can[i][j] = true;
    }

    for(int i = 1; i <= n+1; ++i) for(int j = 1; j <= m+1; ++j) dist[i][j] = 1e9;
    dist[1][1] = 0;

    for(int i = 1; i <= n+1; ++i)
    {
        for(int j = 1; j <= m+1; ++j)
        {
            dist[i][j+1] = min(dist[i][j+1], dist[i][j]+100);
            dist[i+1][j] = min(dist[i+1][j], dist[i][j]+100);
            if(can[i][j]) dist[i+1][j+1] = min(dist[i+1][j+1], dist[i][j]+DIAGONAL);
        }
    }
    cout << round(dist[n+1][m+1]) << "\n";
    return 0;
}   