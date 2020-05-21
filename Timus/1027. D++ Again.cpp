/* 

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

string str = "", validArith = "=+-*/0123456789)(";
int ptr = 0, n;
bool valid = true;

bool IsOpenComment()
{
    return (ptr+1 < n && str[ptr] == '(' && str[ptr+1] == '*');
}

bool IsCloseComment()
{
    return (ptr+1 < n && str[ptr] == '*' && str[ptr+1] == ')');
}

// If valid, ptr ends 1 character after closing bracket
void ProcessComment()
{
    ptr += 2;
    while(ptr < n && !IsCloseComment())
    {
        ++ptr;
    }
    if(ptr == n)
    {
        valid = false;
        return;
    }
    ptr += 2;
}

// If valid, ptr ends 1 character after closing bracket
void ProcessArithmetic()
{
    int cntOpen = 1; // Count of unmatched open brackets
    ++ptr;

    while(ptr < n && cntOpen > 0)
    {
        if(IsOpenComment())
        {
            ProcessComment();
            continue;
        }
        else if(str[ptr] == '(')
        {
            ++cntOpen;
        }
        else if(str[ptr] == ')')
        {
            --cntOpen;
        }
        else if(validArith.find(str[ptr]) == validArith.npos && !(str[ptr] == '\n'))
        {
            valid = false;
            return;
        }
        ++ptr;
    }

    if(cntOpen > 0)
    {
        valid = false;
        return;
    }    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string temp;
    while(getline(cin, temp))
    {
        str += temp;
    }
    
    n = str.size();
    while(ptr < n)
    {
        if(IsOpenComment())
        {
            ProcessComment();
        }
        else if(str[ptr] == '(')
        {
            ProcessArithmetic();
        }
        else if(str[ptr] == ')')
        {
            valid = false;
            break;
        }
        else
        {
            ++ptr;
        }
    }

    (valid) ? cout << "YES\n" : cout << "NO\n";
    return 0;  
}