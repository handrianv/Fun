/* 
    TODO: Shit code. Refactor
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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

vector<vector<char>> vec;
int n, m, k;

vector<int> getCost_1()
{
    vector<int> res(ceil(m/2.0));
    for(int i = 0; i < ceil(m/2.0); ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            //cout << "vec " << j << " " << i << " " << vec[j][i] << endl; 
            res[i] += (vec[j][i] != vec[j][m-i-1]);
        }
    }
    return res;
}

vector<int> getCost_2()
{
    vector<int> res(ceil(m/2.0));
    for(int i = 0; i < ceil(m/2.0); ++i)
    {
        for(int j = 0; j < ceil(n/2.0); ++j)
        {
            pi topLeft = {j, i}, topRight = {j, m-i-1};
            pi bottomLeft = {n-j-1, i}, bottomRight = {n-j-1, m-i-1};
            set<pi> s; s.insert(topLeft); s.insert(topRight); s.insert(bottomLeft); s.insert(bottomRight);
            vector<int> cnt(30);
            for(auto& pos : s) ++cnt[vec[pos.first][pos.second]-'a']; 
            res[i] += (s.size() - *(max_element(cnt.begin(), cnt.end())));
        }
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m >> k;
    vec = vector<vector<char>>(n+5, vector<char>(m+5));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) cin >> vec[i][j];
    }

    vector<int> cost1 = getCost_1();
    //for(int i = 0; i < cost1.size(); ++i) cout << "cost1 " << i << " " << cost1[i] << endl;
    vector<int> cost2 = getCost_2();
    //for(int i = 0; i < cost2.size(); ++i) cout << "cost2 " << i << " " << cost2[i] << endl;
    int costMid = 0;
    if(m % 2 != 0)
    {
        costMid = cost2.back();
        cost1.pop_back(); cost2.pop_back();
    }

    vector<int> cost3(cost1.size());
    for(int i = 0; i < cost1.size(); ++i) cost3[i] = cost2[i] - cost1[i];
    //for(int i = 0; i < cost2.size(); ++i) cout << "cost3 " << i << " " << cost3[i] << endl; 
    sort(cost3.begin(), cost3.end());

    int ansNoMid = 0;
    for(int i = 0; i < ceil(k/2.0); ++i) ansNoMid += cost3[i];
    int ansWithMid = 1e9;
    if(m % 2 != 0)
    {
        //cout << "costmid " << costMid << endl;
        ansWithMid = costMid;
        for(int i = 0; i < ceil((k-1)/2.0); ++i) ansWithMid += cost3[i];
    }
    //cout << "without with " << ansNoMid << " " << ansWithMid << endl;
    int ans = accumulate(cost1.begin(), cost1.end(), 0);
    //cout << "ans raw " << ans << endl;
    if(k == m && (m % 2 != 0)) ans += ansWithMid;
    else ans += min(ansNoMid, ansWithMid);
    cout << ans << "\n";
    return 0; 
}