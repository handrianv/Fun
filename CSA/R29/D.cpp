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

int GetMove(vector<int>& freq)
{
    int sumfreq = 0, maxfreq = 0;
    for(int i = 0; i < 26; ++i)
    {
        sumfreq += freq[i];
        maxfreq = max(maxfreq, freq[i]);
    }
    return (sumfreq-maxfreq);
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    int k;
    cin >> k;
    string str;
    cin >> str;
    int n = str.size();

    vector<int> freqOdd(30), freqEven(30);
    int ans = 0, left = 0;
    for(int right = 0; right < n; ++right)
    {
        int curr = str[right]-'a';
        (right % 2 != 0) ? ++freqOdd[curr] : ++freqEven[curr];
        int need = GetMove(freqOdd) + GetMove(freqEven);
        while(need > k && left <= right)
        {
            curr = str[left] - 'a';
            (left % 2 != 0) ? --freqOdd[curr] : --freqEven[curr];
            ++left;
            need = GetMove(freqOdd) + GetMove(freqEven);
        }
        ans = max(ans, right-left+1);
    }
    cout << ans << "\n";
    return 0; 
}