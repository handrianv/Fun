/*
    TODO prettify code.

    The first crucial observation is we can apply pigeonhole principle to this problem; within the first 3 elements there must be 2 that belongs to the first progression.
    This reduces the number of case we need to check to just three: xxo, xox, or oxx, where x and o denotes whether the element belongs to the first or second progression.

    Note to self: before applying any funny greedy idea, ALWAYS test in on sample first -_-
    READ^
    
    We can do it in a somewhat brute-force way; try every possible ending of the first progression.

    Suppose we are at index i:
    -. If the element at index i can extend the current first progression:
        -. Let's try to extend the first progression, and check whether it can ends here. Then the remaining suffix element must be able to merge with the prefix of second progression
        -. What if this element can extend the second progression as well? We don't need to check this case, because it means the first progression must have ended earlier and cannot be extended further
           But if the first progression ended earlier, we have already checked it in the earlier iteration of the loop

    -. If the element at index i cannot extend the first progression
       -. Try extending the second progression. If it can't then there is no answer

    TLDR a nasty casework problem :(
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

const int INF = 1e9;
const tuple<int, int, int> INVALID = {INF, INF, INF};
int n;

tuple<int, int, int> Merge(const vector<int>& vec, const vector<char>& possible, const vector<int>& secondProgression, const int& i)
{
    tuple<int, int, int> secondAns = INVALID;
    // Suffix must be a progression and size after merge >= 2
    if(possible[i+1] && (secondProgression.size() + n-i-1 >= 2))
    {
        // Can we merge end of prefix and start of suffix
        int dPrefix = (secondProgression.size() >= 2) ? secondProgression[1]-secondProgression[0] : -1;
        int dSuffix = (n-i-1 >= 2) ? vec[n-1]-vec[n-2] : -1;

        if(secondProgression.size() == 0)
        {
            secondAns = {vec[i+1], dSuffix, n-i-1};
        }
        else if(secondProgression.size() == 1)
        {
            if(dSuffix == -1) // Suffix must have one element as well bcs we already verified size after merge >= 2
            {
                secondAns = {secondProgression[0], vec[i+1]-secondProgression[0], 2};
            } 
            else if(vec[i+1]-secondProgression[0] == dSuffix)
            {
                secondAns = {secondProgression[0], dSuffix, n-i};
            }
        }
        else
        {
            if(i+1 == n) // Empty suffix
            {
                secondAns = {secondProgression[0], dPrefix, secondProgression.size()};
            }
            else if(i+1 == n-1 && vec[i+1]-secondProgression.back() == dPrefix) // 1 suffix
            {
                secondAns = {secondProgression[0], dPrefix, secondProgression.size()+1};
            }
            else if(dPrefix == dSuffix && vec[i+1]-secondProgression.back() == dPrefix) // > 1 suffix
            {
                secondAns = {secondProgression[0], dPrefix, secondProgression.size()+(n-i-1)};
            }
        }
    }
    return secondAns;
}

tuple<int, int, int> Try(const vector<int>& vec, const vector<char>& possible, int idx1, int idx2)
{
    //cout << "Trying idx " << idx1 << " " << idx2 << "\n";
    int d = vec[idx2] - vec[idx1];
    if(d == 0) return INVALID;

    vector<int> firstProgression = {vec[idx1]};
    vector<int> secondProgression;
    if(!(idx1 == 0 && idx2 == 1)) // If idx1 == 0 && idx2 == 1, then vec[2] might also be part of first prog
    {
        if(idx1 == 0) secondProgression.push_back(vec[1]);
        else secondProgression.push_back(vec[0]);
    }
    
    tuple<int, int, int> firstAns = INVALID, ans = INVALID;
    // Try every length of first progression
    for(int i = idx2; i < n; ++i)
    {
        // Suppose first prog ends here
        if(vec[i] - firstProgression.back() == d)
        {
            firstProgression.push_back(vec[i]);
            firstAns = {vec[idx1], d, firstProgression.size()};

            // Can we make second prog with the remaining element?
            auto secondAns = Merge(vec, possible, secondProgression, i);
             // No possible valid second prog if this element is in first prog, then don't update ans
            if(secondAns != INVALID) ans = min({ans, firstAns, secondAns});
        }
        else // This element must belong to second progression
        {
            secondProgression.push_back(vec[i]);

            // This element can't be part of either first or second prog, so no answer
            if(secondProgression.size() >= 2 && secondProgression.back()-secondProgression[secondProgression.size()-2] != secondProgression[1]-secondProgression[0])
            {
                //cout << "invalid when " << i << "\n";
                break;
            }
        }  
    }

   // cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << "\n";
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> vec[i];
        }

        vector<char> possible(n+1); // Is it possible for suffix ending at i to be a progression
        possible[n] = possible[n-1] = true;
        int d = vec[n-1] - vec[n-2];
        if(d > 0)
        {
            possible[n-2] = true;
            for(int i = n-3; i >= 0; --i)
            {
                possible[i] = possible[i+1] && (vec[i+1]-vec[i] == d);
            }
        }

        auto ans = min({Try(vec, possible, 0, 1), Try(vec, possible, 0, 2), Try(vec, possible, 1, 2)});
        if(get<0>(ans) == INF) cout << "-1\n";
        else cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << "\n";
    }
    return 0;
}

/*

*/