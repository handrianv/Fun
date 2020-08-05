/*
    First let's get the easy case out of the way; Simulate the process once and if element 1 ends up in position k, we can simulate once more and just remove
    the first move that doesn't affect element 1.

    Now to the harder case, if after the simulating the process element x != 1 ends up in position k instead, what should we do?
    The key observation is, the problem statement guarantees existence of solution. This means there must be a move that swaps element 1 with element x somewhere, and we can just remove it.
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

void Update(int& pos, const int& s1, const int& s2)
{
    if(s1 == pos) pos = s2;
    else if(s2 == pos) pos = s1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n, m, k;
    cin >> n >> m >> k;
    --k;
    vector<pi> swaps(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> swaps[i].first >> swaps[i].second;
        --swaps[i].first; -- swaps[i].second;
    }

    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 0);
    for(auto& s : swaps)
    {
        swap(vec[s.first], vec[s.second]);
    }

    if(vec[k] == 0)
    {
        int pos0 = 0;
        for(int i = 0; i < m; ++i)
        {
            int s1 = swaps[i].first, s2 = swaps[i].second;
            if(s1 != pos0 && s2 != pos0)
            {
                cout << (i+1) << "\n";
                return 0;
            }
            Update(pos0, s1, s2);
        }
    }
    else
    {
        int pos0 = 0, posTarget = vec[k];
        for(int i = 0; i < m; ++i)
        {
            int s1 = swaps[i].first, s2 = swaps[i].second;
            if((s1 == pos0 && s2 == posTarget) || (s2 == pos0 && s1 == posTarget))
            {
                cout << (i+1) << "\n";
                return 0;
            }
            Update(pos0, s1, s2); Update(posTarget, s1, s2);
        }
    }
    
    return 0;
}

/*

*/