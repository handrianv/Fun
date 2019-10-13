/* 

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
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

void NearestSmaller(vector<int>& vec, vector<int> dir)
{
    stack<int> st;
    for(int i = 0; i < vec.size(); ++i)
    {
        while(!st.empty() && st.top() > vec[i]) st.pop();
        if(!st.empty()) dir[i] = st.top();
        st.push(vec[i]);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];

    vector<int> le(n, -1), ri(n, n);
    stack<pi> st; // {num, index}
    st.push({-1, -1});

    for(int i = 0; i < n; ++i)
    {
        while(st.top().first >= vec[i]) st.pop();
        le[i] = st.top().second;
        st.push({vec[i], i});
    }

    while(!st.empty()) st.pop();
    st.push({-1, n});

    for(int i = n-1; i >= 0; --i)
    {
        while(st.top().first >= vec[i]) st.pop();
        ri[i] = st.top().second;
        st.push({vec[i], i});
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ans = max(ans, (ll)vec[i] * (ri[i]-le[i]-1));
    }
    cout << ans << "\n";
    return 0; 
}           