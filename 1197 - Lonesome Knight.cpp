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

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

bool Valid(int x, int y)
{
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    while(n--)
    {
        int ans = 0;
        string str;
        cin >> str;
        int x = str[0] - 'a' + 1;
        int y = str[1] - '0';
        for(int i = 0; i < 8; ++i)
        {
            ans += Valid(x+dx[i], y+dy[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}   