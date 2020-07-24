/*

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

const int MAXN = 25005;
vector<int> graph(MAXN);
int color[MAXN]; bool hasCycle;
int inStack = 1, finished = 2;

void DFS(int start)
{
    stack<int> st;
    st.push(start);
    color[start] = inStack;
    while(!st.empty())
    {
        int curr = st.top();
        int nxt = graph[curr];
        if(color[nxt] != inStack && color[nxt] != finished && nxt != 0)
        {
            st.push(nxt);
            color[nxt] = inStack;
        }
        else if(color[nxt] == inStack)
        {
            hasCycle = true;
            return;
        }
        else
        {
            st.pop();
            color[curr] = finished;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int cnt0 = 0;
        for(int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            graph[i] = x;
            cnt0 += (x == 0);
        }
        if(cnt0 != 1)
        {
            cout << "NO\n";
        }
        else
        {
            for(int i = 1; i <= n; ++i)
            {
                if(color[i] != inStack && color[i] != finished) DFS(i);
            }
            (!hasCycle) ? cout << "YES\n" : cout << "NO\n";
        }

        hasCycle = false; inStack += 2; finished += 2;
    }
    return 0;
}