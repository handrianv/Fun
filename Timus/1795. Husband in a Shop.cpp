/*
    When a person arrives that needs X quantity of product Y, but there are only Z < X item left (Z > 0)
    We can simply set X = Z, and swap this person with the next person
    With this the implementation becomes much simpler
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


typedef pair<string, int> psi;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int m;
    cin >> m;
    map<string, int> cnt; 
    for(int i = 0; i < m; ++i)
    {
        int x; string trash, name;
        cin >> x >> trash >> name;
        cnt[name] += x;
    }

    int n;
    cin >> n;
    vector<psi> vec(n);
    for(int i = 0; i < n; ++i)
    {
        int x; string trash, name;
        cin >> x >> trash >> name;
        vec[i] = {name, x};
    }

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ++ans;
        int rem = cnt[vec[i].first];
        if(i+1 == n || rem == 0) continue;
        if(rem >= vec[i].second)
        {
            rem -= vec[i].second;
            cnt[vec[i].first] = rem;
        }
        else
        {
            vec[i].second = rem;
            swap(vec[i], vec[i+1]);
            --i;
        }
        
        //cout << "now ans " << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}
