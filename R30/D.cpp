/*
    TODO: Better algo
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

typedef tree<
    string,
    null_type,
    less<string>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

struct Trie{
    Trie* nxt[30];
} *root;

void insert(Trie* curr, const string& str, int idx)
{
    if(idx == str.size()) return;
    if(curr->nxt[str[idx]-'a'] == NULL) curr->nxt[str[idx]-'a'] = new Trie();
    insert(curr->nxt[str[idx]-'a'], str, idx+1);
}

bool check(Trie* curr, const string& str, int idx)
{
    if(idx == str.size()) return true;
    if(curr->nxt[str[idx]-'a'] == NULL) return false;
    return check(curr->nxt[str[idx]-'a'], str, idx+1);
}

int n, k;
vector<string> group[30];
vector<int> groupLen[30];

bool comp(const string& a, const string& b)
{
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

bool check(int limit)
{
    int has = 0;
    for(int i = 0; i < 26; ++i)
    {
        root = new Trie();
        vector<string> vec = group[i]; vector<int> vecLen = groupLen[i];
        if(vecLen.size() == 0 || vecLen[0] > limit) continue;
        auto iter = upper_bound(vecLen.begin(), vecLen.end(), limit);
        --iter;
        for(int j = (iter-vecLen.begin()); j >= 0; --j)
        {
            if(!check(root, vec[j], 0))
            {
                ++has;
                insert(root, vec[j], 0);
            }
            if(has >= k) return true;
        }
    }
    return (has >= k);
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        group[str[0]-'a'].push_back(str);
    }
    for(int i = 0; i < 26; ++i)
    {
        sort(group[i].begin(), group[i].end(), comp);
        groupLen[i] = vector<int>(group[i].size());
        for(int j = 0; j < group[i].size(); ++j) groupLen[i][j] = group[i][j].size();
    } 

    int left = 1, right = 1e6, ans = -1;
    while(left <= right)
    {
        auto mid = left + (right-left) / 2;
        if(check(mid))
        {
            right = mid-1;
            ans = mid;
        } 
        else left = mid+1;
    }
    cout << ans << "\n";
    return 0;
}   

