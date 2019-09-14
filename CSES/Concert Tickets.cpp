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
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    while(n--)
    {
        int num;
        cin >> num;
        s.insert(num);
    }
    while(m--)
    {
        int num;
        cin >> num;
        auto iter = s.upper_bound(num);
        if(iter != s.begin())
        {   
            --iter;
            cout << (*iter) << "\n";
            s.erase(iter);
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}