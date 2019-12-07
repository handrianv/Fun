/*
    Do sliding median while maintaining sum of each set. 
    We can get cost for left half in O(1) by subtracting (sum if all element equal median) - (actual sum of left half). Similarly for right half.
*/
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; 

multiset<int> l, r;
ll lSum, rSum;

void Rebalance()
{
    if(l.size() > r.size()+1)
    {
        auto iter = l.rbegin();
        lSum -= (*iter);
        rSum += (*iter);
        r.insert(*iter);
        l.erase(--l.end());
    }
    else if(r.size() > l.size()+1)
    {
        auto iter = r.begin();
        lSum += (*iter);
        rSum -= (*iter);
        l.insert(*iter);
        r.erase(iter);
    }
}

void Insert(int x)
{
    if(!l.empty() && x <= (*(l.rbegin())))
    {
        l.insert(x);
        lSum += x;
    } 
    else
    {
        r.insert(x);
        rSum += x;
    } 
    Rebalance();
}

void Delete(int x)
{
    if(l.count(x))
    {
        l.erase(l.find(x));
        lSum -= x;
    } 
    else
    {
        r.erase(r.find(x));
        rSum -= x;
    } 
    Rebalance();
}

int Get()
{
    if(r.size() > l.size()) return (*r.begin());
    else return (*l.rbegin());
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> vec(n+5);
    for(int i = 1; i <= n; ++i) cin >> vec[i];
    for(int i = 1; i < k; ++i) Insert(vec[i]);
    
    for(int i = k; i <= n; ++i)
    {
        Insert(vec[i]);
        ll med = Get();
        //cout << "med is " << med << endl;
        ll ans = (med * l.size() - lSum) + (rSum - r.size() * med);
        cout << ans;
        (i == n) ? cout << "\n" : cout << " ";
        Delete(vec[i-k+1]);
    }
    return 0; 
}