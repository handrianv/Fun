/*
    Let's represent the problem as graph: compartments are nodes and baffles are edges.
    Clearly we need to open at least one baffle for every compartment. So lower bound of answer is (n-1) where n = number of compartment.
    Take any spanning tree of the graph, then we can always do it in (n-1) moves. Just open it starting from leaf.
    So answer is (n-1)
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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    cin >> str;
    set<string> s; s.insert(str);
    while(str != "#")
    {
        cin >> str;
        if(str != "#")
        {
            int dashIdx = find(str.begin(), str.end(), '-') - str.begin();
            string a = str.substr(0, dashIdx);
            string b = str.substr(dashIdx+1);
            s.insert(a); s.insert(b);
        }
    }
    cout << (s.size()-1) << "\n";
    return 0;
}
/*

*/