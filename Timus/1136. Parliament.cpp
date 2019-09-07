/*
    Given a left-first post order traversal, return a right-first post order traversal.
    By reversing the given traversal, we get a right-first pre order traversal. We can use this to restore the actual tree.
    After that just do DFS
*/

#include <stdio.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

vector<int> graph[100000];
int post[3005];
int n;

void RecoverTree()
{
    stack<int> st;
    st.push(post[0]);
    for(int i = 1; i < n; ++i)
    {
        if(post[i] > st.top())
        {
            graph[st.top()].push_back(post[i]);
        }
        else
        {
            int par;
            while(!st.empty() && st.top() > post[i])
            {
                par = st.top();
                st.pop();
            }
            graph[par].push_back(post[i]);
        }
        st.push(post[i]);
    }
}

void DFS(int curr)
{
    if(graph[curr].size() == 1)
    {
        DFS(graph[curr][0]);
    }
    else if(graph[curr].size() == 2)
    {
        DFS(max(graph[curr][0], graph[curr][1]));
        DFS(min(graph[curr][0], graph[curr][1]));
    }
    cout << curr << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n;
    for(int i = n-1; i >= 0; --i) cin >> post[i];
    RecoverTree();
    DFS(post[0]);
    return 0;
}