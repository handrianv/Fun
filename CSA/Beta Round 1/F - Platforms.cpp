/*
    Sort the platforms and balls by their x endpoint.
    Let's first check for a platform whether it needs to be moved at all or not. We can simply binary search whether any ball intersects it.

    Now consider the length of gap formed by two adjacent balls. Then for each platform, we want to find the nearest gap to the right (or left) whose length >= this platform's length.
    This is similar to finding nearest bigger number in array, and indeed it can be solved in a similar way.
    For example, we can do a sweep line of increasing x, and maintain a multiset (in place of the stack of the usual array algorithm) of platforms that currently have no matches.
    Then just like the algorithm on array, everytime we encounter a gap, we can pop from this multiset every platform whose length <= this gap. This gives N log N complexity.

    The rest is implementation details. One useful trick is we can implement such function just once to find the nearest gap only to the right or left.
    For the other direction, we can reuse the function by passing in the platforms and gaps with the coordinates mirrored
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

const int MAXN = 1e5+5;
int optimal[MAXN]; // For platform i, the optimal cost of movement
int n, m;

struct Platform {
    int left, right, idx;

    Platform(){}
    Platform(int lleft, int rright, int iidx) : left(lleft), right(rright), idx(iidx) {}

    bool operator<(const Platform& other)
    {
        return left < other.left;
    }
};

struct Event {
    bool type; // {0: platform, 1: balls}
    int x, len, idx;

    Event(){}
    Event(bool t, int xx, int llen, int iidx) : type(t), x(xx), len(llen), idx(iidx) {} 

    bool operator<(const Event& other)
    {
        return x < other.x;
    }
};

void Solve(const vector<Platform>& platforms, const vector<int>& balls, const vector<char>& needToMove)
{
    vector<Event> events;
    for(int i = 0; i < n; ++i)
    {
        if(needToMove[platforms[i].idx])
        {
            events.push_back({0, platforms[i].left, platforms[i].right-platforms[i].left, platforms[i].idx});
        }
    }
    for(int i = 0; i < m-1; ++i)
    {
        events.push_back({1, balls[i], balls[i+1]-balls[i], -1});
    }
    events.push_back({1, balls[m-1], 2000000000, -1});
    sort(events.begin(), events.end());

    multiset<pair<int, pi>> s; // {length of platform, {x, idx}}
    for(auto& event : events)
    {
        if(event.type == 0) s.insert({event.len, {event.x, event.idx}});
        else
        {
            while(!s.empty())
            {
                auto curr = *(s.begin());
                if(event.len < curr.first) break;
                optimal[curr.second.second] = min(optimal[curr.second.second], event.x - curr.second.first);
                s.erase(s.begin());
            }
        }
    }
}


void Reverse(vector<Platform>& platforms, vector<int>& balls)
{
    for(auto& platform : platforms)
    {
        swap(platform.left, platform.right);
        platform.left *= -1; platform.right *= -1;
    }
    sort(platforms.begin(), platforms.end());

    for(auto& ball : balls)
    {
        ball *= -1;
    }
    sort(balls.begin(), balls.end()); 
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m;
    vector<Platform> platforms(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> platforms[i].left >> platforms[i].right;
        platforms[i].idx = i;
        optimal[i] = 2e9;
    }
    sort(platforms.begin(), platforms.end());

    vector<int> balls(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> balls[i];
    }
    sort(balls.begin(), balls.end());

    vector<char> needToMove(n);
    for(int i = 0; i < n; ++i)
    {
        auto nearestBall = upper_bound(balls.begin(), balls.end(), platforms[i].left) - balls.begin();
        if(nearestBall < m && balls[nearestBall] < platforms[i].right)
        {
            needToMove[platforms[i].idx] = true;
        }
    }   

    Solve(platforms, balls, needToMove);
    Reverse(platforms, balls);
    Solve(platforms, balls, needToMove);

    ll ans = 0;
    for(int i = 0; i < n; ++i) if(optimal[i] != 2e9) ans += optimal[i];
    cout << ans << "\n";
    return 0;
}

/*

*/