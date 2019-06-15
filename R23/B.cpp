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
typedef pair<ll, int> pli;

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;
    
const int MAXN = 1000;
bool special[MAXN+5];
pi coord[MAXN+5];

int dist(int i, int j)
{
    return (abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second));
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; ++i)
    {
        cin >> special[i] >> coord[i].first >> coord[i].second;
    }

    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        int closex = 1e9, closey = 1e9;
        for(int i = 0; i < n; ++i)
        {
            if(special[i])
            {
                closex = min(closex, dist(i, x));
                closey = min(closey, dist(i, y));
            } 
        } 
        int ans = min(dist(x, y), closex+closey+t);
        cout << ans << "\n";
    }
    return 0;
}   

