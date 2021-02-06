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
#define EPS 1e-9
#define CeilDiv(a, b) ((a+b-1)/b)
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 2e5+5;
ll preftree[4*MAXN], sufftree[4*MAXN], sumtree[4*MAXN], segtree[4*MAXN];
int arr[MAXN];

void Calc(int idx)
{
    int lIdx = idx*2, rIdx = idx*2+1;
    sumtree[idx] = sumtree[lIdx] + sumtree[rIdx];
    preftree[idx] = max(preftree[lIdx], sumtree[lIdx] + preftree[rIdx]);
    sufftree[idx] = max(sufftree[rIdx], sumtree[rIdx] + sufftree[lIdx]);
    segtree[idx] = max({segtree[lIdx], segtree[rIdx], sufftree[lIdx] + preftree[rIdx]});
}

void Build(int idx, int left, int right)
{
    if(left == right)
    {
        sumtree[idx] = arr[left];
        preftree[idx] = sufftree[idx] = segtree[idx] = max(0, arr[left]);
        return;
    }
    int mid = left + (right-left) / 2;
    Build(idx*2, left, mid);
    Build(idx*2+1, mid+1, right);
    Calc(idx);
}

void Update(int idx, int left, int right, int k)
{
    if(left == right)
    {
        sumtree[idx] = arr[left];
        preftree[idx] = sufftree[idx] = segtree[idx] = max(0, arr[left]);
        return;
    }
    int mid = left + (right-left) / 2;
    if(k <= mid) Update(idx*2, left, mid, k);
    else Update(idx*2+1, mid+1, right, k);
    Calc(idx);
}


int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    Build(1, 0, n-1);
    while(m--)
    {
        int k, x;
        cin >> k >> x;
        --k;
        arr[k] = x;
        Update(1, 0, n-1, k);
        cout << segtree[1] << "\n";
    }
    return 0;
}
 
/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
cout << setprecision for doubles!! Costed me half a day of life!!
*/  