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

const int MAXN = 1e6+5;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> cnt(MAXN);
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        ++cnt[num];
    }
    
    for(int i = MAXN; i >= 1; --i)
    {
        int temp = 0;
        for(int j = i; j <= MAXN; j += i)
        {
            temp += cnt[j];
            if(temp >= 2)
            {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}