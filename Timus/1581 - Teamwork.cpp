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


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> ans;
    int curr = -1, cnt = 0;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        if(curr == -1 || curr == num) ++cnt;
        else
        {
            ans.push_back({cnt, curr});
            cnt = 1;
        }
        curr = num;
    }
    ans.push_back({cnt, curr});

    for(int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].first << " " << ans[i].second;
        (i == ans.size()-1) ? cout << "\n" : cout << " ";
    }
    return 0;
}   