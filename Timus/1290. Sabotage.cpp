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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

vector<int> Do(vector<int>& vec)
{
    sort(vec.begin(), vec.end());
    vector<int> result;
    int ptr = 0;
    for(int i = 0; ; ++i)
    {
        while(ptr < vec.size() && vec[ptr] <= i) ++ptr;
        if(ptr == vec.size()) return result;
        else result.push_back((int)vec.size()-ptr);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
    vector<int> result = Do(vec);
    result = Do(result);
    for(const auto& num : result) cout << num << "\n";
    return 0;
}   