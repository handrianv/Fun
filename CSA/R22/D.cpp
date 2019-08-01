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

string str, ans;
int n;

bool check(int p)
{
    for(int i = 0; i < p; ++i)
    {
        set<char> s;
        for(int j = i; j < n; j += p) s.insert(str[j]);
        if(s.find('0') != s.end() && s.find('1') != s.end()) return false;
        char ch;
        if(s.size() == 1 && s.find('?') != s.end()) ch = '0';
        else ch = (s.find('0') != s.end()) ? '0' : '1'; 
        for(int j = i; j < n; j += p) ans[j] = ch;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> str;
    n = str.size();
    ans = string(n, 'x');
    for(int p = 1; p <= n; ++p)
    {
        if(n % p != 0) continue;
        if(check(p))
        {
            cout << ans << "\n";
            return 0;
        }
    }
    return 0;
}   