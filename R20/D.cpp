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

ull k, n;
ull dp[20][10][2];
string strn, str;
bool hasNonZero = false;

string toStr(ull num)
{
    string res = "";
    while(num > 0)
    {
        res += ((num % 10) + '0');
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

ull DP(int len, int num, bool tight)
{
    //cout << "len " << len << " num " << num << endl;
    if(len == str.size()-1) return dp[len][num][tight] = 1;
    if(dp[len][num][tight] != -1) return dp[len][num][tight];
    ull res = 0;

    if(tight)
    {
        int limit = (str[len+1]-'0');
        if(num+1 <= limit) res += DP(len+1, num+1, num+1 == limit);
        if(num > 0 && num-1 <= limit) res += DP(len+1, num-1, num-1 == limit);
        if(num <= limit) res += DP(len+1, num, (num == limit));
    }
    else
    {
        if(num < 9) res += DP(len+1, num+1, false);
        if(num > 0) res += DP(len+1, num-1, false);
        res += DP(len+1, num, false);
    }
    
    return dp[len][num][tight] = res;
}

ull solve()
{
    memset(dp, -1, sizeof(dp));
    ull res = 0;
    for(int start = str.size()-1; start >= 0; --start)
    {
        int limit = (start == 0) ? (str[0]-'0') : 9;
        for(int i = 1; i <= limit; ++i)
        {
            res += DP(start, i, (start == 0 && i == limit));
        }
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> k >> n;
    strn = toStr(n);

    str = strn;
    ull fn = solve();
    //cout << fn << endl;

    ull ans = 0;
    ull left = n+1, right = LONG_LONG_MAX;
    while(left <= right)
    {
        ull mid = left + (right-left) / 2;
        str = toStr(mid);
        ull fmid = solve();
        //cout << "when mid " << mid << " solve " << fmid << endl;

        if(fmid-fn >= k)
        {
            ans = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    cout << ans << endl;
    return 0;
}   