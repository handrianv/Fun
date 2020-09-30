/*
    Often when we have problem where a property should hold for all subarray / substring, it's enough to check that the property holds
    for small subarray, and it can be proven that it'd automatically hold for all longer length as well.

    In this problem, we want the property "no palindrome" to hold for all substrings with length > 1. It's (well?) known that we only need this to hold
    for substring of size 2 and 3; then it'd hold for all substrings.

    Proof is simple, for any palindrome with length > 1:
    -. If the palindrome has even length, the two middle element must be equal, so there must exist palindrome with size = 2.
    -. If the palindrome has odd length, let s[m] be the middle character, then s[m-1] = s[m+1], so {s[m-1], s[m], s[m+1]} forms a palindrome with size = 3.
    So if we have no palindrome with size 2 and 3, there exist neither even nor odd length palindrome i.e. there exist no palindrome.

    Since in this problem we only have 3 characters, if we fix the first two character then the rest of the string is determined; the next character must 
    always be different from the previous two, and there is only one choice.
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


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    const int LIMIT = 100000;
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "a\nb\nc\n";
        return 0;
    }
    if(n*6 > LIMIT)
    {
        cout << "TOO LONG\n";
        return 0;
    }

    string base = "abc";
    do {
        string s = "";
        while(s.size() < n) s += base;
        while(s.size() > n) s.pop_back();
        cout << s << "\n";
    } while(next_permutation(base.begin(), base.end()));

    return 0;
}
 
/*
 
*/ 