/*
    Do BFS with names as nodes. Beware of the case where "Isenbaev" doesn't exist.
*/

#include <stdio.h>
#include <bits/stdc++.h>
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

map<string, int> nameToId;
vector<int> graph[305];
int dist[305];

void BFS()
{
    memset(dist, -1, sizeof(dist));
    if(nameToId.find("Isenbaev") == nameToId.end()) return;
    int source = nameToId["Isenbaev"];
    queue<int> que;
    que.push(source);
    dist[source] = 0;

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();
        for(auto neighbor : graph[curr])
        {
            if(dist[neighbor] == -1)
            {
                dist[neighbor] = dist[curr] + 1;
                que.push(neighbor);
            }
        }
    }
}

void Convert(const string& name, int& id)
{
    if(nameToId[name] == 0)
    {
        nameToId[name] = id;
        ++id;
    }
}

void AddEdge(int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    int id = 1;

    for(int i = 0; i < n; ++i)
    {
        string name1, name2, name3;
        cin >> name1 >> name2 >> name3;
        Convert(name1, id); Convert(name2, id), Convert(name3, id);
        int id1 = nameToId[name1], id2 = nameToId[name2], id3 = nameToId[name3];
        AddEdge(id1, id2); AddEdge(id2, id3); AddEdge(id1, id3);
    }

    BFS();

    for(auto kv : nameToId) 
    {
        cout << kv.first << " ";
        (dist[kv.second] == -1) ? cout << "undefined\n" : cout << dist[kv.second] << "\n";
    }
    return 0;
}   