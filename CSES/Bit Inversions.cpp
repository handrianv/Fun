/*
    Do something similar to problem "Subarray Sum Queries", with slight modification in recurrence
    TODO: There exist simpler solution with set
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

const int MAXN = 2e5+5;
int preftree[4*MAXN], sufftree[4*MAXN], anstree[4*MAXN];
string str;
int n;

void Calc(int curr, int left, int right)
{
    int mid = left + (right-left) / 2;
    bool canJoinPrefixSuffix = (str[mid] == str[mid+1]);
    anstree[curr] = max(anstree[curr*2], max(anstree[curr*2+1], (sufftree[curr*2] + preftree[curr*2+1]) * canJoinPrefixSuffix));
    preftree[curr] = max(preftree[curr*2], (preftree[curr*2] + preftree[curr*2+1]) * (preftree[curr*2] == mid-left+1) * canJoinPrefixSuffix);
    sufftree[curr] = max(sufftree[curr*2+1], (sufftree[curr*2+1] + sufftree[curr*2]) * (sufftree[curr*2+1] == right-mid) * canJoinPrefixSuffix);
}

void Build(int curr, int left, int right)
{
    if(left == right)
    {
        preftree[curr] = sufftree[curr] = anstree[curr] = 1;
        return;
    }
    int mid = left + (right-left) / 2;
    Build(curr*2, left, mid);
    Build(curr*2+1, mid+1, right);
    Calc(curr, left, right);
}

void Update(int curr, int left, int right, int updateIdx)
{
    if(left == right) return;
    int mid = left + (right-left) / 2;
    if(updateIdx <= mid)
        Update(curr*2, left, mid, updateIdx);
    else
        Update(curr*2+1, mid+1, right, updateIdx);
    Calc(curr, left, right);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> str;
    n = str.size();
    Build(1, 0, n-1);
    int m;
    cin >> m;

    while(m--)
    {
        int pos;
        cin >> pos;
        --pos;
        (str[pos] == '1') ? str[pos] = '0' : str[pos] = '1';
        Update(1, 0, n-1, pos);
        Update(1, 0, n-1, pos);
        cout << anstree[1];
        (m == 0) ? cout << "\n" : cout << " ";
    }
    return 0; 
}