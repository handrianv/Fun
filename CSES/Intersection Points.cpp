/*
    Every vertical segment is a query "how many intersections there are from y1 to y2"
    Every horizontal segment is an update "increase count of y in x1 and decrease it in (x2+1)"
    Sort query by x and process it using fenwick tree
*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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
 
const int MAXN = 1e5+5;
const int MAXNUM = 1e6+5;
int fenwick[2*MAXNUM+5];
int n;

void Add(int idx, int val)
{
    while(idx <= 2*MAXNUM)
    {
        fenwick[idx] += val;
        idx += LSOne(idx);
    }
}

int Query(int idx)
{
    int res = 0;
    while(idx > 0)
    {
        res += fenwick[idx];
        idx -= LSOne(idx);
    }
    return res;
}

int Query(int left, int right)
{
    return Query(right) - ((left == 0) ? 0 : Query(left-1));
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    vector<pair<pi, pi>> queries; // {x, type}, {value}
    for(int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += MAXNUM; y1 += MAXNUM; x2 += MAXNUM; y2 += MAXNUM;
        if(y1 == y2)
        {
            queries.push_back({{x1, 1}, {y1, y1}});
            queries.push_back({{x2+1, -1}, {y1, y1}});
        }
        else
        {
            queries.push_back({{x1, 2}, {y1, y2}});
        }
    }
    sort(queries.begin(), queries.end());
    ll ans = 0;
    for(const auto& query : queries)
    {
        int type = query.first.second;
        if(type != 2) Add(query.second.first, type);
        else
        {
            int res = Query(query.second.first, query.second.second);
            ans += res;
        }
    }
    cout << ans << "\n";
    return 0; 
}