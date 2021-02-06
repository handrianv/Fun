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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    vector<char> visited(n);
    vector<int> temp; temp.reserve(n);
    int ans = 0;

    for(int i = 0; i < n && !visited[i]; ++i)
    {
        // Group numbers
        int idx = i;
        while(!visited[idx])
        {
            visited[idx] = true;
            temp.push_back(vec[idx]);
            idx += k; if(idx >= n) idx -= n;
        }

        // Then min cost is median
        sort(temp.begin(), temp.end());
        int med = temp[temp.size()/2];
        for(auto& v : temp)
        {
            ans += abs(med-v);
        }
        temp.clear();
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/  