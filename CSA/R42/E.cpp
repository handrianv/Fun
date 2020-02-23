/* 

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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXBIT = 30;

struct Trie{
    bool val;
    Trie* nxt[2];
} *rootOdd, *rootEven;

void Insert(Trie *root, int val)
{
    Trie *curr = root;
    for(int i = 0; i < MAXBIT; ++i)
    {
        bool b = (val & (1<<i));
        if(curr->nxt[b] == NULL) curr->nxt[b] = new Trie();
        curr = curr->nxt[b];
    }
}

int Query(Trie *root, int val)
{
    int ans = 0;
    Trie *curr = root;
    for(int i = 0; i < MAXBIT; ++i)
    {
        bool valBit = (val & (1<<i));
        bool target = valBit ^ 1;

        if(curr->nxt[target] != NULL) ans += (1<<i);
        else target = valBit;

        curr = curr->nxt[target];
    }
    return ans;
}

int GetMaxEven(const vector<int>& vec)
{
    rootOdd = new Trie(); rootEven = new Trie();
    Insert(rootEven, 0);
    Insert(rootOdd, vec[0]);

    int n = vec.size();
    int ans = 0, curr = vec[0];
    for(int i = 1; i < n; ++i)
    {
        curr ^= vec[i];
        Trie *temp = ((i+1) % 2 != 0) ? rootOdd : rootEven;
        ans = max(ans, Query(temp, curr));
        Insert(temp, curr);
    }
    return ans;
}

int GetMaxOdd(const vector<int>& a, const vector<int>& b)
{
    rootOdd = new Trie();
    int n = a.size(), m = b.size();
    for(int i = 0; i < n; ++i)
    {
        int curr = 0;
        for(int j = i; j < n; ++j)
        {
            curr ^= a[j];
            if((j-i+1) % 2 != 0) Insert(rootOdd, curr);
        }
    }

    int ans = 0;
    for(int i = 0; i < m; ++i)
    {   
        int curr = 0;
        for(int j = i; j < m; ++j)
        {
            curr ^= b[j];
            if((j-i+1) % 2 != 0) ans = max(ans, Query(rootOdd, curr));
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];

    int ans = max(GetMaxEven(a), GetMaxEven(b));
    ans = max(ans, GetMaxOdd(a, b));
    cout << ans << "\n";

    return 0; 
}