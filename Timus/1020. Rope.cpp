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

const double PI = acos(-1.0);

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n; double r;
    cin >> n >> r;
    vector<pd> points(n);
    for(int i = 0; i < n; ++i) cin >> points[i].first >> points[i].second;
    points.push_back(points[0]);

    double ans = PI * 2 * r;
    for(int i = 0; i < n; ++i)
    {
        ans += hypot(points[i].first - points[i+1].first, points[i].second-points[i+1].second);
    }
    cout << fixed << setprecision(2);
    cout << ans << "\n";    
    return 0; 
}       