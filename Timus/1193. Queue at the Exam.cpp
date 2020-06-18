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
#define CEIL()
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Student {
    int t1, t2, t3;
    Student(){}
    Student(int a, int b, int c) : t1(a), t2(b), t3(c) {}
};

bool operator <(const Student& a, const Student& b)
{
    return a.t1 < b.t1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<Student> vec(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i].t1 >> vec[i].t2 >> vec[i].t3;
    }
    sort(vec.begin(), vec.end());

    int ans = 0, t = 0;
    for(auto& student : vec)
    {
        t = max(student.t1, t) + student.t2;
        ans = max(ans, max(0, t-student.t3));
    }
    cout << ans << "\n";
    return 0;
}
 
/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/