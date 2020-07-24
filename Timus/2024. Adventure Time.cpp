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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int comb[30][30];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    comb[0][0] = 1;
    for(int i = 1; i <= 26; ++i)
    {
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; ++j)
        {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
  
    string str; int k;
    cin >> str >> k;

    vector<int> freq(30);
    for(auto& ch : str) ++freq[ch-'a'];

    multiset<int> s;
    for(auto& f : freq) if(f > 0) s.insert(f);

    int lowestFreq = 1e9, cnt = 0, ans1 = 0;
    while(k > 0 && !s.empty())
    {
        int f = *(s.rbegin());
        s.erase(--s.end());
        ans1 += f;
        if(f < lowestFreq)
        {
            lowestFreq = f;
            cnt = 1;
        }
        else
        {
            ++cnt;
        }
        --k;
    }

    int ans2 = 1;
    if(!s.empty())
    {
        int cnt2 = cnt;
        while(!s.empty())
        {
            int f = *(s.rbegin());
            s.erase(--s.end());
            if(f < lowestFreq) break;
            ++cnt2;
        }
        ans2 = comb[cnt2][cnt];
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}

/*

*/