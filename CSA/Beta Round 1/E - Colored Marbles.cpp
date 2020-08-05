/*
    First, let's solve the problem if there are no lies.
    We can group each number x together and count its frequency freq[x], and it'll add x * ceil(freq[x] / x) to the final answer
    For example, if there are 8 5's:
    5 5 5 5 5 5 5 5
    Then the first 5 can each be a ball of red color. But starting from the 6th ball, it needs to be a different color
    (5 5 5 5 5) --> these are reds (5 5 5) --> these are blues
    Note that these adds 10 to the final answer, not 8, because even though there are only 3 5's, the actual number of blue ball is 5. Alex just didn't pick the other two.

    Okay, now we go to the problem when Alex lies exactly once.
    Suppose we want to pick a ball with quantity x as a lie, then two things happen:
    -. If this is the only ball in the group, then the answer decreases by x
       For example, if there are 6 5's
       (5 5 5 5 5) (5)
       These originally adds 10 to the final answer. But if the final 5 is a lie, then the answer decreases by 5. 
    -. Then we should change x to another quantity y != x. So in this case, we should change it to something that is not 5.
       --. If any other quantity y still have remaining slot, we can just change x to that y.
           For example, if there are 5 3's
           (3 3 3) (3 3)
           Then the second group of three can take one more number. So we change the 5 to 3
       --. If not, then we can make a new group of size 1 if x != 1, else we make new group of size 2
    

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
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<int, int> freq;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            ++freq[x];
        }

        ll answerWithoutLie = 0;
        int cntPositiveRem = 0;
        for(auto& kv : freq)
        {
            answerWithoutLie += kv.first * ((kv.second+kv.first-1) / kv.first);
            cntPositiveRem += (kv.second % kv.first);
        }

        ll answerWithLie = 1e18;
        for(auto& kv : freq)
        {
            //cout << "num " << kv.first << " freq " << kv.second << "\n";
            ll newAns = answerWithoutLie;
            int rem = kv.second % kv.first;
            if(rem == 1 || kv.first == 1) newAns -= kv.first; // Last ball in a group
            if(cntPositiveRem - (rem == 1) <= 0) (kv.first > 1) ? ++newAns : newAns += 2; // Need to make new group with different quantity
            answerWithLie = min(answerWithLie, newAns);
        }
        cout << answerWithLie << "\n";
    }
    return 0;
}

/*

*/