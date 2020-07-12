/*
    The optimal strategy is for each player to greedily take as much element in-between them, and then take all element to the left / right of them.
    
    Proof
    WLOG the first player is on the left. Let sum[i] = prefix sum up to i'th element.
    If both player uses above strategy, then first player gets sum[i + d/2] score, where d is distance between first and second player. Half of the d element goes to first player, another half to the second.
    Suppose player 2 doesn't use above strategy, so at some point he moves to the right instead of left. Then it's clear that first player can get more than d/2 element,
    and the first i element still belongs to first player as well.

    Another way of thinking
    The two player can never swap places i.e. left player becomes right player.
    Suppose at some point they are adjacent. If the sum of left part of array > right part, then the left player can just move left to prevent right player from overtaking him.
    The same reasoning applies if sum of right part > left part.
    So the only numbers up for contest is numbers between them. And it's not hard to see that a greedy strategy is optimal.

    Beware special case where both player starts at the same position
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
    int n;
    cin >> n;
    vector<int> vec(n+5);
    for(int i = 1; i <= n; ++i)
    {
        cin >> vec[i];
        vec[i] += vec[i-1];
    }
    int firstP, secondP;
    cin >> firstP >> secondP;

    int d = abs(firstP-secondP);
    int extra = d / 2;
    int score1 = 0, score2 = 0;
    if(firstP < secondP)
    {
        score1 = vec[firstP + extra];
    }
    else if(firstP > secondP)
    {
        score1 = vec[n] - vec[firstP - extra - 1];
    }
    else
    {
        score1 = max(vec[firstP], vec[n] - vec[firstP-1]);
    }
    
    score2 = vec[n] - score1;
    cout << score1 << " " << score2 << "\n";
    return 0;
}