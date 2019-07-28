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

int dist[7][7];

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    for(int i = 1; i <= 5; ++i) for(int j = 1; j <= 5; ++j) cin >> dist[i][j];
    vector<int> order = {2, 3, 4};
    int ans = 1e9;
    vector<int> ansVec;
    do {
        if(order[2] == 3) continue;
        int temp = dist[1][order[0]] + dist[order[0]][order[1]] + dist[order[1]][order[2]] + dist[order[2]][5];
        if(temp < ans )
        {
            ans = temp;
            ansVec = order;
        }
    } while(next_permutation(order.begin(), order.end()));
    
    cout << ans << "\n1 ";
    for(auto num : ansVec) cout << num << " ";
    cout << "5\n";
    return 0;
}   