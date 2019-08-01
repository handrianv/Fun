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
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cout << fixed << setprecision(10);
    int n, q;
    cin >> n >> q;
    vector<double> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];

    double allSum = 0;
    vector<double> elemSum(n);
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 0)
        {
            int idx, val;
            cin >> idx >> val;
            --idx;
            elemSum[idx] += val;
            allSum += val;
        }
        else
        {
            int idx;
            cin >> idx;
            --idx;
            double res = vec[idx] + elemSum[idx] - ((allSum-elemSum[idx]) / (double)(n-1));
            cout << res << "\n";
        }
        
    }
    return 0;
}   

