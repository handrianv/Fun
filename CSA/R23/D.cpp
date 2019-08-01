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

const int MAXN = 1e5;
int coord[MAXN+5];
int mi[MAXN+5], ma[MAXN+5];
int n;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> coord[i];
    for(int i = 0; i < n; ++i) cin >> mi[i] >> ma[i];

    int currMi = mi[n-1], currMa = ma[n-1];
    int ans = (currMa-currMi+1);
    for(int i = n-2; i >= 0; --i)
    {
        int d = coord[i+1] - coord[i];
        int nxtMi = 1e9+5;
        if(d-mi[i] >= currMi && d-mi[i] <= currMa) nxtMi = mi[i];
        if(d-currMa >= mi[i] && d-currMa <= ma[i]) nxtMi = min(nxtMi, d-currMa);
    
        int nxtMa = -1;
        if(d-ma[i] >= currMi && d-ma[i] <= currMa) nxtMa = ma[i];
        if(d-currMi >= mi[i] && d-currMi <= ma[i]) nxtMa = max(nxtMa, d-currMi);\

        if(nxtMi == 1e9+5 || nxtMa == -1)
        {
            cout << "0\n";
            return 0;
        }

        if(nxtMa == ma[i]) ans -= (d-ma[i] - currMi);
        if(nxtMi == mi[i]) ans -= (currMa - (d-mi[i]));
        currMi = nxtMi;
        currMa = nxtMa;
    }
    cout << ans << "\n";
    return 0;
}   

