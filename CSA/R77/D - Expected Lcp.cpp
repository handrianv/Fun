/*
    First, let's derive the formula for "expected LCP".
    It's really just the mean; Over all possible pairing of strings, sum up their LCP length, and divide by number of way to choose the pairings.
    
    So the formula is:
    Sum of all LCP length / Combination(n, 2)

    The problem is now reduced to "count sum of all LCP length". Since this is a problem about prefix, it's natural to think about Trie, and indeed we can solve this using Trie.
    We simply add another variable "f" to the nodes of the Trie, denoting the frequency of this prefix.
    For example, a Trie like this:
      root
    /
    a(f=10)
    /
    b(f=7)
    Means there are 10 strings with prefix "a", and 7 strings with prefix "ab". Note that the 7 strings with prefix "ab" is also part of the 10 strings with prefix "a".

    Then each node in the Trie contributes Combination(f, 2) to the sum of LCP, since there are f pairing of strings to choose from (convince yourself of this).
    Note that in counting the contribution of prefix "ab", when we are at node "b" we shouldn't count the contribution of "a" because it's already counted before. So there is no need to multiply by length of prefix.
*/  
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <bitset>
#include <random>
#include <chrono>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
   
struct Trie {
    Trie* nxt[30];
    int freq;

    Trie()
    {
        for(int i = 0; i < 30; ++i) nxt[i] = NULL;
        freq = 1;
    }
} *root = new Trie();

void Insert(const string& str)
{
    Trie* curr = root;
    for(auto& ch : str)
    {
        //cout << "Traversing " << ch << "\n";
        int idx = (ch-'a');
        if(curr->nxt[idx] == NULL)
        {
            curr->nxt[idx] = new Trie();
        }
        else
        {
            ++curr->nxt[idx]->freq;
        }
        curr = curr->nxt[idx];
    }
}

ll Count(Trie* curr)
{
    ll ans = 0;
    for(int i = 0; i < 26; ++i)
    {
        if(curr->nxt[i] == NULL) continue;
        ll f = curr->nxt[i]->freq;
        ans += (f*(f-1)/2LL);
        ans += Count(curr->nxt[i]);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        Insert(str);
    }
    ll nume = Count(root);
    ll denom = (ll)n*(ll)(n-1)/2LL;
    ld ans = (ld)nume/(ld)denom;
    cout << fixed << setprecision(9);
    cout << ans << "\n";
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
cout << setprecision for doubles!! Costed me half a day of life!!
*/  