/* 
    Pick leftmost, lowermost point and do polar sort around it. Then the line formed by this point and the middle point is the required line.
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// https://vlecomte.github.io/cp-geo.pdf
struct Point {
    ll x, y; int idx;
    Point(){}
    Point(ll xx, ll yy, int ii) : x(xx), y(yy), idx(ii) {}

    Point operator+(Point p) {return {x+p.x, y+p.y, idx};}
    Point operator-(Point p) {return {x-p.x, y-p.y, idx};}
    bool operator<(Point p) {if(x == p.x)  return y < p.y; else return x < p.x;}
};

ll Cross(const Point& p1, const Point& p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

bool Half(const Point& p)
{
    assert(p.x != 0 || p.y != 0);
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

void PolarSort(vector<Point>& v)
{
    sort(v.begin()+1, v.end(), [&](Point p1, Point p2) {
        return make_tuple(Half(p1-v[0]), 0) < make_tuple(Half(p2-v[0]), Cross(p1-v[0],p2-v[0]));
    });
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i+1;
    }
    for(int i = 1; i < n; ++i)
    {
        if(points[i] < points[0]) swap(points[i], points[0]);
    }
    PolarSort(points);
    cout << points[0].idx << " " << points[n/2].idx << "\n";
    return 0;
}
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/