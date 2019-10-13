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

const int MAXBIT = 31;

struct Node {
    Node* nxt[2];
} *root = new Node();

void Insert(int num)
{
    Node* curr = root;
    for(int i = MAXBIT; i >= 0; --i)
    {
        bool currBit = (num & (1<<i));
        if(curr->nxt[currBit] == NULL) curr->nxt[currBit] = new Node();
        curr = curr->nxt[currBit];
    }
}

int Find(int num)
{
    Node* curr = root;
    int ans = 0;
    for(int i = MAXBIT; i >= 0; --i)
    {
        bool currBit = (num & (1<<i));
        if(curr->nxt[currBit^1] != NULL)
        {
           ans += (1 << i);
           curr = curr->nxt[currBit^1]; 
        }
        else
        {
            curr = curr->nxt[currBit];
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    int currXor = 0, ans = 0;
    Insert(0);
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        currXor ^= num;
        ans = max(ans, Find(currXor));
        Insert(currXor);
    }
    cout << ans << "\n";
    return 0; 
}           