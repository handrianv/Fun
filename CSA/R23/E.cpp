/*
    Shit code. Refactor when revisiting problem
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
typedef pair<ll, int> pli;

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

const int MAXN = 2005;
const int MAXNUM = 2e5+5;

// Sieve
vector<int> primes;
bool isPrime[MAXNUM];

// Array
int n;
int arr[MAXN];
int idxOf[MAXNUM];

// MaxFlow
int source, sink;
vector<int> graph[MAXN];
int flow[MAXN][MAXN], capacity[MAXN][MAXN];
int level[MAXN], ptr[MAXN];

// Vertex Cover
vector<int> tempGraph[MAXN];
bool visited[MAXN];

bool BFS()
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    que.push(source);
    level[source] = 0;

    while(!que.empty())
    {
        int curr = que.front();
        que.pop();
        //cout << "now curr " << curr << endl;
        if(curr == sink) return true;

        for(auto neighbor : graph[curr])
        {
            //cout << "checking neighbor " << neighbor << " level " << level[neighbor] << " cap flow " << capacity[curr][neighbor] << " " << flow[curr][neighbor] << endl;
            if(level[neighbor] == -1 && capacity[curr][neighbor] > flow[curr][neighbor])
            {
                level[neighbor] = level[curr] + 1;
                que.push(neighbor);
            }
        }
    }

    return false;
}

int DFS(int curr, int pushed)
{
    if(curr == sink) return pushed;

    for(int i = ptr[curr]; i < graph[curr].size(); ++i)
    {
        int neighbor = graph[curr][i];
        if(level[neighbor] == level[curr] + 1 && capacity[curr][neighbor] > flow[curr][neighbor])
        {
            int augment = DFS(neighbor, min(pushed, capacity[curr][neighbor] - flow[curr][neighbor]));
            if(augment == 0) continue;
            else
            {
                flow[curr][neighbor] += augment;
                flow[neighbor][curr] -= augment;
                ptr[curr] = i;
                return augment;
            }
        }
    }

    ptr[curr] = graph[curr].size();
    return 0;
}

int MaxFlow()
{
    int result = 0;
    while(BFS())
    {
        memset(ptr, 0, sizeof(ptr));
        int augment = 0;
        while(augment = DFS(source, 2e9))
        {
            result += augment;
        }
    }
    return result;
}

void addEdge(int node1, int node2)
{
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
    capacity[node1][node2] = capacity[node2][node1] = flow[node2][node1] = 1;
}

void dfs(int node)
{
    visited[node] = true;
    for(auto neighbor : tempGraph[node])
    {
        if(!visited[neighbor]) dfs(neighbor);
    }
}

// Edge list already a pair of {left vertex, right vertex}
vector<int> getVertexCover()
{
    vector<int> dfsStart;
    for(int i = 1; i <= n; ++i)
    {
        if(arr[i-1] % 2 == 0) continue;
        bool incident = false;
        for(auto neigbor : graph[i])
        {
            if(neigbor == source || neigbor == sink) continue;
            if(flow[i][neigbor] == 1)
            {
               // cout << "flow between " << i << " and " << neigbor << endl;
                incident = true;
                tempGraph[neigbor].push_back(i);
            }
            else
            {
                tempGraph[i].push_back(neigbor);
            }
        }
        if(!incident) dfsStart.push_back(i);
    }

    for(auto node : dfsStart)
    {
       // cout << "start from " << node << endl;
        if(!visited[node])
            dfs(node);
    }

    vector<int> cover;
    for(int i = 1; i <= n; ++i)
    {
        if(arr[i-1] % 2 == 0) continue;
        for(auto neighbor : graph[i])
        {
            if(flow[i][neighbor] == 1)
            {
                if(!visited[i]) cover.push_back(i);
                if(visited[neighbor]) cover.push_back(neighbor);
            }
        }
    }
    return cover;
}

    
int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i < MAXNUM; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(int j = i+i; j < MAXNUM; j += i) isPrime[j] = false;
        }
    }

    memset(idxOf, -1, sizeof(idxOf));
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        arr[i] = num;
        idxOf[num] = (i+1);
    }

    vector<pi> edgeList;
    source = 0, sink = n+1;
    for(auto prime : primes)
    {
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] > prime || arr[i] % 2 == 0) continue;
            int other = idxOf[prime-arr[i]];
            if(other != -1 && other != i+1)
            {
                addEdge(i+1, other);
              //  cout << "edge between " << (i+1) << " " << other << endl;
                int toSource, toSink;
                addEdge(source, i+1);
                addEdge(other, sink);
            }
        }
    }

    cout << MaxFlow() << "\n";
    vector<int> cover = getVertexCover();
    for(int i = 0; i < cover.size(); ++i)
    {
        cout << arr[cover[i]-1];
        (i == cover.size()-1) ? cout << "\n" : cout << " ";
    }
    return 0;
}   

