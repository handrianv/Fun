/* 
    If a character doesn't exist, we just use that one as the answer.
    Now suppose all character occurs at least once. Then the answer must contain one of these character as the very first character.
    It's optimal to greedily choose the farthest one to the right, because by choosing this one we have less "candidates" for the next character.
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    vector<char> vec = {'A', 'C', 'G', 'T'};
    string str;
    cin >> str;

    map<char, queue<int>> occurence;
    for(int i = 0; i < str.size(); ++i)
    {
        occurence[str[i]].push(i);
    }

    int last = -1;
    string ans = "";
    bool found = false;
    for(int i = 1; i <= str.size(); ++i)
    {
        int nxtLast = last;
        for(const auto& ch : vec)
        {
            while(!occurence[ch].empty() && occurence[ch].front() <= last) occurence[ch].pop();
            if(occurence[ch].empty())
            {
                ans += ch;
                found = true;
                break;
            }     
            nxtLast = max(nxtLast, occurence[ch].front());       
        }
        if(found) break;
        last = nxtLast;
        //cout << "new last is " << last << "\n";
        ans += str[last];
    }
    if(!found) ans += 'A';
    cout << ans << "\n";
    return 0;
}       