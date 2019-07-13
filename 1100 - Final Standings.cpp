/*
    Since bubble sort is a stable sort, we'll use merge sort
    EZ way: use built-in stable sort function
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

const int MAXN = 150005;
pi temp[MAXN+5];

void Merge(vector<pi>& vec, int left, int right)
{
    int mid = left + (right-left)/2;
    int ptr1 = left, ptr2 = mid+1, tPtr = 0;

    while(ptr1 <= mid || ptr2 <= right)
    {
        if(ptr1 > mid) temp[tPtr++] = vec[ptr2++];
        else if(ptr2 > right) temp[tPtr++] = vec[ptr1++];
        else if(vec[ptr1].first >= vec[ptr2].first) temp[tPtr++] = vec[ptr1++];
        else temp[tPtr++] = vec[ptr2++];
    }

    tPtr = 0;
    for(int i = left; i <= right; ++i, ++tPtr) vec[i] = temp[tPtr];
}

void MergeSort(vector<pi>& vec, int left, int right)
{
    int mid = left + (right-left) / 2;
    if(left < right)
    {
        MergeSort(vec, left, mid);
        MergeSort(vec, mid+1, right);
        Merge(vec, left, right);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<pi> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i].second >> vec[i].first;
    MergeSort(vec, 0, n-1);
    for(auto p : vec) cout << p.second << " " << p.first << "\n";
    return 0;
}   