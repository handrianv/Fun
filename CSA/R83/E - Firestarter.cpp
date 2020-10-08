/*
    TODO: Retry problem, simplify implementation. Complete this explanation after retry.
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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int ll
const int MAXN = 2e5+5;
vector<pi> graph[MAXN]; // {weight, node}
int n, m, q;

// The starting "fire" nodes will be the source
// And the shortest path to each node is the time for that node to start burning
vector<ll> Dijkstra(int extraNode, map<int, int>& tOfExtra)
{
    vector<ll> dist(extraNode+5, -1);
    set<pli> s;
    for(int i = n+1; i < extraNode; ++i)
    {
        dist[i] = tOfExtra[i]; // The time it takes for special node to start burning is their initial distance  
        //cout << "dist " << i << "=" << dist[i] << "\n";
        s.insert({dist[i], i}); 
    }     

    while(!s.empty())
    {
        auto curr = *s.begin();
        s.erase(s.begin());
        ll currDist = curr.first; auto currNode = curr.second;

        for(auto& v : graph[currNode])
        {
            auto w = v.first, nxtNode = v.second;
            ll nxtDist = currDist + w;
            if(dist[nxtNode] == -1)
            {
                dist[nxtNode] = nxtDist;
                s.insert({nxtDist, nxtNode});
            }
            else if(nxtDist < dist[nxtNode])
            {
                s.erase({dist[nxtNode], nxtNode});
                dist[nxtNode] = nxtDist;
                s.insert({nxtDist, nxtNode});
            }
        }
    }

    return dist;
}

void AddEdge(const int& a, const int& b, const int& l)
{
    graph[a].push_back({l, b});
    graph[b].push_back({l, a});
}

void AddEdge2(const int& a, const int& b, const int& l, vector<pair<pi, int>>& edges)
{
    AddEdge(a, b, l);
    edges.push_back({{a, b}, l});
}

// Given starting fire time of each node and length of edge, compute time it takes to burn
double Compute(ll t1, ll t2, const double& l)
{
    if(t1 > t2) swap(t1, t2);
    double dt = t2-t1;
    return (t1 + dt + (l-dt) / 2.0);
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> m >> q;

    // Read edges, but don't actually add it to the graph yet
    vector<pair<pi, int>> edges(m); // {edge, weight} 
    map<pi, int> edgeLength;
    for(int i = 0; i < m; ++i)
    {
        int a, b, l;
        cin >> a >> b >> l;
        if(a > b) swap(a, b);
        edges[i] = {{a, b}, l};
        edgeLength[{a, b}] = l;
    }

    // We'll keep the list of special nodes in each edge, measured by distance from the lower numbered endpoint
    int extraNode = n+1;
    map<pi, vector<pi>> specialOnEdge; // {edge, {distance from A, idx}}
    map<int, int> tOfExtra; // Starting time of fire of extra node
    while(q--)
    {
        int t, a, b, x;
        cin >> t >> a >> b >> x;
        int l = edgeLength[{min(a, b), max(a, b)}];
        int distFromA = x, distFromB = l-x;
        if(a > b)
        {
            swap(a, b);
            swap(distFromA, distFromB);
        }
        specialOnEdge[{a, b}].push_back({distFromA, extraNode});
        tOfExtra[extraNode] = t;
        ++extraNode;
    }

    // Now we'll build the actual graph
    vector<pair<pi, int>> trueEdges; trueEdges.reserve(m+q+5);
    for(auto& edge : edges)
    {
        vector<pi> specials = specialOnEdge[edge.first];
        int a = edge.first.first, b = edge.first.second, l = edge.second;

        // If there are no special nodes on this edge, just connect them
        if(specials.empty())
        {
            AddEdge2(a, b, l, trueEdges);
            continue;
        }

        // Else, first we need to sort the specials by distance. For simplicity, pretend A and B itself are special
        sort(specials.begin(), specials.end());

        // Then we need to remove duplicates; if two fire started at the same distance X, we prioritize the earlier fire
        vector<pi> temp; temp.reserve(specials.size());
        temp.push_back(specials[0]);
        for(int i = 1; i < (int)specials.size(); ++i)
        {
            if(specials[i].first == temp.back().first && tOfExtra[specials[i].second] < tOfExtra[temp.back().second])
            {
                temp.back().second = specials[i].second;
            }
            else if(specials[i].first > temp.back().first)
            {
                temp.push_back(specials[i]);
            }
        }
        specials = temp;

        // Now we just connect each adjacent node
        AddEdge2(a, specials[0].second, specials[0].first, trueEdges);
        for(int i = 1; i < (int)specials.size(); ++i)
        {
            AddEdge2(specials[i-1].second, specials[i].second, specials[i].first - specials[i-1].first, trueEdges);
        }
        AddEdge2(specials.back().second, b, l-specials.back().first, trueEdges);
    }

    vector<ll> dist = Dijkstra(extraNode, tOfExtra);
    double ans = 0;
    for(auto& edge : trueEdges)
    {
        int a = edge.first.first, b = edge.first.second, l = edge.second;
        //cout << "Edge info: " << "{" << a << ", " << b << "}, distA=" << dist[a] << " distB=" << dist[b] << " L=" << l << "\n";
        ans = max(ans, Compute(dist[a], dist[b], l));
    }
    cout << fixed << setprecision(9);
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 