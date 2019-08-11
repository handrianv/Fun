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

const int MAXN = 105;
int n;
int arr[MAXN][MAXN];

int Kadane(const vector<int>& vec)
{
    int currMax = -1e9, allMax = -1e9;
    for(int i = 1; i <= n; ++i)
    {
        currMax = max(vec[i], vec[i]+currMax);
        allMax = max(allMax, currMax);
    }
    return allMax;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int ans = -1e9;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cin >> arr[i][j];
    for(int i = 1; i <= n; ++i)
    {
        vector<int> vec(n+5);
        for(int j = i; j <= n; ++j)
        {
            for(int k = 1; k <= n; ++k)
            {
                vec[k] += arr[j][k];
            }

            ans = max(ans, Kadane(vec));
        }
    }
    cout << ans << "\n";
    return 0;
}   