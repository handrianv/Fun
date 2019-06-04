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
    int n;
    cin >> n;

    unordered_map<int, int> cnt;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        ++cnt[num];
    }

    unordered_map<int, vector<int>> cnt2;
    for(auto kv : cnt)
    {
        cnt2[kv.second].push_back(kv.first);
    }

    for(auto kv : cnt2) if(kv.second.size() == 1) cout << kv.second[0] << "\n";
    return 0;
}