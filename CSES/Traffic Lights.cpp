/* 
    Tip 1: cin.tie(0) because time limit is tight
    Tip 2: Read https://codeforces.com/blog/entry/68127 because problem statement is a bit ambiguous
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int x, n;
    cin >> x >> n;

    multiset<pi> intervals;
    multiset<int> len;
    intervals.insert({1, x});
    len.insert(x);

    while(n--)
    {
        int pos;
        cin >> pos;
        auto iter = intervals.upper_bound(pi(pos, 1e9+7));
        --iter;
        pi currInterval = (*iter);

        intervals.erase(iter);
        len.erase(len.lower_bound(currInterval.second - currInterval.first+1));
        //cout << "erased " << currInterval.first << " " << (currInterval.second) << "\n";

        intervals.insert({currInterval.first, pos});
        len.insert(pos-currInterval.first+1);
        //cout << "inserted " << currInterval.first << " " << pos << "\n";
        
        intervals.insert({pos+1, currInterval.second});
        len.insert({currInterval.second-pos});
        //cout << "inserted " << (pos+1) << " " << currInterval.second << "\n";
        
        cout << (*(len.rbegin()));
        (n == 0) ? cout << "\n" : cout << " ";
    }
    return 0; 
}           