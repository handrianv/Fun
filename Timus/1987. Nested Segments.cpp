/*
    Note that due to the problem constraint, if we have two segments i and j, i < j, then either:
    -. Segment i is completely disjoint from segment j
    -. Or segment j is fully contained within segment i (so segment j has shorter length)
    Which means for any point x, if there are two segments that contains it, the one to the right will be the shorter one.
    So for any point x the answer is simply the rightmost segment that contains it.

    Since we are given the query in sorted order, we can process each query by maintaining a stack of "valid" segments for the current query.
    For each query with point x, we want to maintain the following invariant: 
    -. The stack contain all segments that covers x, sorted in decreasing length. 
    Visually, the top of the stack will contain the shortest segment that contains x, the next top contains the segment that contains the top segment, and so on until the bottom of stack contains the outermost segment that contains x.

    To maintain this invariant, for each query:
    1. We first pop from the stack all segment that does not contain x.
    2. We push to the stack all segment that contains x. We stop this when we encounter a segment with left endpoint > x. Since segments are already sorted by left endpoint, we know all next segment can't contain x.
       Note that in the second step, when we encounter segment with left <= x but right < x, we can safely ignore it forever, because the query is given to us in sorted order. If this segment is to the left of the current query, it'll be to the left of all future query as well.
    And the answer for each query is the topmost segment in the stack (or -1 if it's empty). Each segment is pushed once, popped once, so complexity is linear.

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
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> segments(n);
    for(auto& v : segments)
    {
        cin >> v.first >> v.second;
    }
    int m;
    cin >> m;
    stack<int> st; 
    int idx = 0;
    while(m--)
    {
        int p;
        cin >> p;

        // Pop segments from previous iteration that does not contain p
        while(!st.empty() && segments[st.top()].second < p) st.pop();

        // Try pushing candidate segment with left <= p
        while(idx < n && segments[idx].first <= p)
        {
            // If right < p, then it can't contain any next p. So no need to push
            if(segments[idx].second >= p)
            {
                st.push(idx);
            }
            ++idx;
        }

        (st.empty()) ? cout << "-1\n" : cout << st.top()+1 << "\n";
    }
    return 0;
}
 
/*
 
*/ 