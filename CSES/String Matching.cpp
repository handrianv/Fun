/* 
    TODO: Try to solve with Z-algorithm
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXN = 1e6+5;
const ll MOD1 = 1e9+7, MOD2 = 1e9+9;
const ll P1 = 419, P2 = 23917;
ll pow1[MAXN], pow2[MAXN];
ll prefixHash_1[MAXN], prefixHash_2[MAXN];

int toInt(char ch)
{
    return (ch-'0');
}

ll MyMod(ll a, ll b, ll MOD)
{
    return (((b-a) % MOD) + MOD) % MOD;
}

// Return pair {hash1, hash2}
// Set "save" to true to save hash in global array
pll Hash(const string& str, bool save)
{
    int n = str.size();
    vector<int> temp1(n+5), temp2(n+5);
    temp1[1] = temp2[1] = toInt(str[0]);
 
    for(int i = 2; i <= n; ++i)
    {
        int num = toInt(str[i-1]);
        temp1[i] = (temp1[i-1] + (pow1[i-1] * num) % MOD1) % MOD1;
        temp2[i] = (temp2[i-1] + (pow2[i-1] * num) % MOD2) % MOD2;
    }
 
    if(save)
    {
        for(int i = 1; i <= n; ++i)
        {
            prefixHash_1[i] = temp1[i];
            prefixHash_2[i] = temp2[i];
        }
    }
    return {temp1[n], temp2[n]};
}

pll Subhash(int left, int right)
{
    return {MyMod(prefixHash_1[left-1], prefixHash_1[right], MOD1), MyMod(prefixHash_2[left-1], prefixHash_2[right], MOD2)};
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < MAXN; ++i)
    {
        pow1[i] = (P1 * pow1[i-1]) % MOD1;
        pow2[i] = (P2 * pow2[i-1]) % MOD2;
    } 

    string n, m;
    cin >> n >> m;
    pll hashInput = Hash(n, true);
    pll hashPattern = Hash(m, false);
    int ans = 0;
    for(int i = 1; i + m.size() - 1 <= n.size(); ++i)
    {
        pll curr = Subhash(i, i+m.size()-1);
        if((curr.first == (hashPattern.first * pow1[i-1]) % MOD1) && (curr.second == (hashPattern.second * pow2[i-1]) % MOD2)) 
            ++ans;
    }
    cout << ans << "\n";
    return 0;
}   