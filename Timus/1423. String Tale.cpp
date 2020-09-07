/*
    Notice that a cyclic shift of length k is simply cutting suffix of length k and making it prefix.
    For every k we can compare the prefix & suffix of the two strings. There are multiple ways: hashing, KMP (append the string to itself), Z-function; pick your poison.
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
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;
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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if(s == t)
    {
        cout << "0\n";
        return 0;
    }

    HashRange HR1, HR2;
    HR1.add(s), HR2.add(t);

    for(int i = 0; i < n-1; ++i)
    {
        H hsPrefix = HR1.hash(0, n-i-2), hsSuffix = HR1.hash(n-i-1, n-1);
        H htPrefix = HR2.hash(0, i), htSuffix = HR2.hash(i+1, n-1);
        if(htPrefix == hsSuffix && htSuffix == hsPrefix)
        {
            cout << (i+1) << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
 
/*
 
*/  