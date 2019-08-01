/*
    There is only one unique node present in the path A-B, B-C, A-C
    Informal proof:
    -. If there are more than one common node then there will be cycle in the tree

    The common node D must be one of LCA(A,B), LCA(B,C), LCA(A,C)
    Informal proof:
    -. Consider the subtree S rooted at LCA(A,B). We can separate it into two cases
        -. Node C is outside S, then the path C-A & C-B must pass through LCA(A,B). In this case LCA(A,B) is the answer.
        -. Node C is inside S. Consider direct children of LCA(A,B). Let the subtree that contains A SA, and the one that contains B SB. SA and SB cannot be the same.
            -. If C is inside SA, then answer is LCA(A,C), since the path B-A/B-C must pass through here. Similar logic if C is inside SB.
            -. If C is inside neither of them, then LCA(A,B) = LCA(B,C) = LCA(A,C);
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

const int MAXN = 1e5+5;
const int LOGN = 17;
int n, q;
vector<int> graph[MAXN];
int parent[MAXN+5][LOGN+5], depth[MAXN+5];

void DFS(int curr, int prev)
{
    depth[curr] = depth[prev] + 1;
    parent[curr][0] = prev;

    for(int i = 1; i <= LOGN; ++i)
    {
        parent[curr][i] = parent[parent[curr][i-1]][i-1];
    }

    for(auto neighbor : graph[curr])
    {
        if(neighbor != prev) DFS(neighbor, curr);
    }
}

int LCA(int x, int y)
{
    if(depth[x] > depth[y]) swap(x, y);

    int jump = 0;
    for(int i = depth[y]-depth[x]; i > 0; i/=2)
    {
        if(i&1) y = parent[y][jump];
        ++jump;
    }

    if(x==y) return x;

    for(int i = LOGN; i >= 0; --i)
    {
        if(parent[x][i] != parent[y][i])
        {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}

int Dist(int a, int b)
{
    return depth[a] + depth[b] - 2*depth[LCA(a,b)];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> q;
    for(int i = 0; i < n-1; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    DFS(1, 1);

    while(q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans1 = LCA(a, b), ans2 = LCA(a, c), ans3 = LCA(b, c);
        int ans = (depth[ans1] > depth[ans2]) ? ans1 : ans2;
        if(depth[ans3] > depth[ans]) ans = ans3;
        cout << ans << " " << (Dist(ans, a) + Dist(ans, b) + Dist(ans, c)) << "\n";
    }
    return 0;
}   