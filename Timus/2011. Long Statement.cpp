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
    vector<int> fact(10);
    fact[0] = 1;
    for(int i = 1; i < 10; ++i) fact[i] = i * fact[i-1];

    int n;
    cin >> n;
    vector<int> vec(3);
    int numDistinct = 0;
    for(int i = 0; i< n; ++i)
    {
        int num;
        cin >> num;
        --num;
        ++vec[num];
        numDistinct += (vec[num] == 1);
    }

    if(numDistinct == 1) cout << "No\n";
    else if(numDistinct >= 2)
    {
        if(n >= 6 || numDistinct == 3){ cout << "Yes\n"; return 0; }
        sort(vec.begin(), vec.end());
        int tot = fact[n] / fact[vec.back()] / fact[vec[vec.size()-2]];
        (tot >= 6) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}   