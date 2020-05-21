/* 
    Easy way: std::sort
    Faster way: Notice that max. num is small (5000). So we can do counting sort in O(Max. num)
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MAXNUM = 5005;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> freq(MAXNUM);
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        ++freq[num];
    }

    vector<int> vec; vec.reserve(n);
    for(int i = 1; i <= MAXNUM; ++i)
    {
        while(freq[i])
        {
            vec.push_back(i);
            --freq[i];
        }
    }

    string trash; cin >> trash;
    int k;
    cin >> k;
    while(k--)
    {
        int x;
        cin >> x;
        cout << vec[x-1] << "\n";
    }
    return 0;  
}