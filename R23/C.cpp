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


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m;
    cin >> m >> n;
    vector<ll> vec(m+5);
    for(int i = 1; i <= m; ++i) cin >> vec[i];

    vector<vector<ll>> psum(m+5);
    vector<pi> cycle(m+5, {-1, -1}); // {first idx, second idx} in psum
    int c = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(cycle[i].first == -1)
        {
            int currIdx = i;
            do {
                cycle[currIdx] = {c, psum[c].size()};
                psum[c].push_back(vec[currIdx]);
                if(psum[c].size() > 1) psum[c].back() += psum[c][psum[c].size()-2];
                currIdx = vec[currIdx];
            } while(currIdx != i);
            ++c;
        }
        //cout << "cycle " << i << " is " << cycle[i].first << endl;
    }

    for(int i = 1; i <= m; ++i)
    {
        int cycleNum = cycle[i].first;
        int start = cycle[i].second;
        int csz = psum[cycleNum].size();

        ll ans = 0;
        int need = n;
        ans += (psum[cycleNum].back() * (need / csz));
        need %= csz;
        if(need > 0)
            ans += (psum[cycleNum][min(csz-1, start+need-1)] - ((start == 0) ? 0 : psum[cycleNum][start-1]));
        int remain = max(0, need - (min(csz, start+need)-start));
        if(remain > 0) ans += psum[cycleNum][remain-1];
        cout << ans;
        (i == m) ? cout << "\n" : cout << " ";
    }
    return 0;
}   

