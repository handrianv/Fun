/*
    The crucial observation is that S2 must be a (reversed) prefix of S1. So creating S2 is the same as choosing some prefix of S1.
    We want to minimize |S2|. So we should maximize the length of suffix of S1 that we didn't choose. This suffix must already be a palindrome.
    Now the problem is reduced to finding maximum length suffix that is a palindrome. There are multiple ways to do this faster than O(N^2), such as using rolling hash or KMP.

    Rolling hash
    A string is palindrome if the hash from left to right is equal hash from right to left. So we can compare hash of the original string with the reversed string.

    KMP
    We reverse the string and use KMP to search the longest possible occurence of R(S1) at the suffix. This is easily done by taking the current KMP state when processing the last character.
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

// Credits: https://github.com/bqi343/USACO/blob/master/Implementations/content/strings%20(14)/Light/HashRange%20(14.2).h
const int MOD = 1e9+7;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
typedef array<int, 2> H;
uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);
const H base = {BDIST(rng),BDIST(rng)};

H operator+(H l, H r) 
{ 
	for(int i = 0; i < 2; ++i) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
	return l; 
}
H operator-(H l, H r) 
{ 
	for(int i = 0; i < 2; ++i) if ((l[i] -= r[i]) < 0) l[i] += MOD;
	return l; 
}
H operator*(H l, H r) 
{ 
	for(int i = 0; i < 2; ++i) l[i] = (ll)l[i]*r[i]%MOD;
	return l; 
}
H makeH(char c) { return {c,c}; }

vector<H> pows = {{1,1}};
struct HashRange 
{
	string S; vector<H> cum = {{0,0}};
	void add(char c) { S += c; cum.push_back(base*cum.back()+makeH(c)); }
	void add(const string& s) { for(auto& c : s) add(c); }
	void extend(int len) { while (pows.size() <= len) pows.push_back(base*pows.back()); }
	H hash(int l, int r) 
    { 
        int len = r+1-l; extend(len);
		return cum[r+1]-pows[len]*cum[l]; 
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    cin >> str;
    string r = str; reverse(r.begin(), r.end());
    HashRange hr1, hr2;
    hr1.add(str); hr2.add(r);
    
    int n = str.size(), best = n;
    for(int i = 1; i < n; ++i)
    {
        H h1 = hr1.hash(i, n-1), h2 = hr2.hash(0, n-i-1);
        if( (h1.front() == h2.front()) && (h1.back() == h2.back()))
        {
            best = i;
            break;
        }
    }
    //cout << "best is " << best << "\n";
    string ans = str; 
    for(int i = best-1; i >= 0; --i)
    {
        ans += str[i];
    }
    cout << ans << "\n";
    return 0;
}

// KMP solution
/*
const int MAXN = 1e4;
string str, pat;
int prefix[MAXN+5];
int cut;

void KMP_Preprocess()
{
    prefix[0] = 0;
    for(int i = 1; i < pat.size(); ++i)
    {
        int j = prefix[i-1];
        while(j > 0 && pat[i] != pat[j]) j = prefix[j-1];
        if(pat[i] == pat[j]) ++j;
        prefix[i] = j;
    }
}

int Search()
{
    int curr = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        while(curr > 0 && str[i] != pat[curr]) curr = prefix[curr-1];
        if(str[i] == pat[curr]) ++curr;
        if(i == str.size()-1) cut = curr;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    cin >> str;
    pat = str;
    reverse(pat.begin(), pat.end());
    pat.pop_back();
    KMP_Preprocess();
    Search();

    cout << str;
    for(int i = str.size()-cut-1; i >= 0; --i)
    {
        cout << str[i];
    }
    cout << "\n";

    return 0;
}

/*


/*
Does order matter? Try sorting
Array bounds, overflow, special cases (n=1, n=max)
Reverse the problem, try solving backwards. Count invalid solutions instead of valid one
Count (1..R)-(1..L) instead of (L..R)
*/