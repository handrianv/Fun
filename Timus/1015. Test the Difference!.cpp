/*
    One possible way is to try all rotation of the cube.

    A slightly faster way is to force all cube to obey some specific rotation, for example we can:
    -. Force the number 1 to be on the left face of the cube.
    -. Now the x-axis is fixed (we can't rotate them anymore). We can force the smallest number in the y-z axis to be on top face.
    -. Now both the x-y axis is fixed, so the z-axis (front-back) is also fixed, because we can't rotate it without rotating the x or y axis as well.
    After this it's simple to check if two cubes are equal; they should have the same permutation.
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

// Smallest number on left
void FirstRotation(vector<int>& v)
{
    // If smallest on right
    if(v[1] == 1)
    {
        swap(v[0], v[1]);
        swap(v[2], v[3]);
    }
    // If smallest on front
    else if(v[2] == 1)  
    {
        int tleft = v[0], tright = v[1], tfront = v[2], tback = v[3];
        v[0] = tfront;
        v[1] = tback;
        v[2] = tright;
        v[3] = tleft;
    } 
    // If smallest on back
    else if(v[3] == 1)
    {
        int tleft = v[0], tright = v[1], tfront = v[2], tback = v[3];
        v[0] = tback;
        v[1] = tfront;
        v[2] = tleft;
        v[3] = tright;
    }
    // If smallest on top
    else if(v[4] == 1)
    {
        int tleft = v[0], tright = v[1], ttop = v[4], tbottom = v[5];
        v[0] = ttop;
        v[1] = tbottom;
        v[4] = tright;
        v[5] = tleft;
    }
    // If smallest on bottom
    else if(v[5] == 1)
    {
        int tleft = v[0], tright = v[1], ttop = v[4], tbottom = v[5];
        v[0] = tbottom;
        v[1] = ttop;
        v[4] = tleft;
        v[5] = tright;
    }
}

// Smallest value other than {left, right} on top
void SecondRotation(vector<int>& v)
{
    int mn = (*(min_element(v.begin()+2, v.end())));

    int tfront = v[2], tback = v[3], ttop = v[4], tbottom = v[5];
    // If smallest on front
    if(v[2] == mn)
    {
        v[2] = tbottom;
        v[3] = ttop;
        v[4] = tfront;
        v[5] = tback;
    }
    // If smallest on back
    else if(v[3] == mn)
    {
        v[2] = ttop;
        v[3] = tbottom;
        v[4] = tback;
        v[5] = tfront;
    }
    // If smallest on bottom
    else if(v[5] == mn)
    {
        swap(v[2], v[3]);
        swap(v[4], v[5]);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    map<vector<int>, int> m; // {Dice, index}
    vector<vector<int>> ans;

    for(int i = 0; i < n; ++i)
    {
        vector<int> v(6); // {left, right, front, back, top, bottom}
        cin >> v[0] >> v[1] >> v[4] >> v[2] >> v[5] >> v[3];
        FirstRotation(v);
        SecondRotation(v);
        if(m.count(v))
        {
            ans[m[v]].push_back(i+1);
        }
        else
        {
            ans.push_back({i+1});
            m[v] = ans.size()-1;
        }
    }

    assert(ans.size() > 0);
    cout << ans.size() << "\n";
    for(auto& v : ans)
    {
        int sz = v.size();
        for(int i = 0; i < sz; ++i)
        {
            cout << v[i];
            (i+1 == sz) ? cout << "\n" : cout << " ";
        }
    }
    return 0;
}