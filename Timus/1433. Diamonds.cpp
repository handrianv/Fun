/*
    We can keep the first tetrahedron in the given orientation and try to rotate only the second tetrahedron.
    Try every side of the second tetrahedron as base, then the two tetrahedrons are identical if the "upper faces" are circular permutation of each other.
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
#define CeilDiv(a, b) ((a + b - 1) / b)

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
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;

    // Check circular permutation
    auto Check = [&](const string &a, const string &b) {
        string c = b + b;
        return c.find(a) != c.npos;
    };

    bool can = false;
    string face1 = s1.substr(1);

    // s2 no rotation
    if (s1[0] == s2[0])
    {
        string face2 = s2.substr(1);
        can |= Check(face1, face2);
    }

    // In all of below, face2 is oriented from left to right
    // s2 left front becomes base
    if (s1[0] == s2[1])
    {
        string face2 = "";
        face2 += s2[2];
        face2 += s2[0];
        face2 += s2[3];
        can |= Check(face1, face2);
    }
    // s2 right front becomes base
    if (s1[0] == s2[2])
    {
        string face2 = "";
        face2 += s2[0];
        face2 += s2[1];
        face2 += s2[3];
        can |= Check(face1, face2);
    }
    // s2 back becomes base
    if (s1[0] == s2[3])
    {
        string face2 = "";
        face2 += s2[2];
        face2 += s2[1];
        face2 += s2[0];
        can |= Check(face1, face2);
    }
    (can) ? cout << "equal\n" : cout << "different\n";
    return 0;
}

/*
Overflow. ll does not guarantee no overflow; be careful of multiplication
set vs multiset
set.lower_bound, NOT lower_bound(set);
multiset.erase(ITERATOR, NOT NUMBER) to erase just a single element
setprecision for doubles!! Costed me half a day of life!!
*/