/* 
    Suppose the string is not a palindrome
    -. Split the string into left half and right half. Suppose the left half is "1234" and right half is "abcd".
    -. For it to be a palindrome, reverse(left half) == right half. So we want to know, if we keep incrementing right half, can we get into (reverse)left half?
       So we just compare whether "abcd" <= "4321". If true, then we can get to "4321" by incrementing "abcd", and that's the smallest greater palindrome
    -. If "abcd" > "4321", suppose we keep incrementing "abcd" until it reaches "0000", what happens to left half?
       Well, the left half will increase by one. It becomes "12345". Don't forget the carry, if left half is "1299" then after incrementing it becomes "1300".
       Whatever left half becomes, we can definitely reach it by incrementing "0000"
       
    Summary:
    1. Compare reverse(left half) and right half. If right half <= reverse(left half), answer is left half + reverse(left half)
    2. If not, increment left half. Answer is incremented left half + reverse(incremented left half).
    
    Note that when incrementing left half, it's impossible to get all zeroes. Why?
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
typedef pair<double, double> pd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

bool isPalindrome(const string& str)
{
    return (str == string(str.rbegin(), str.rend()));
}

int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    string str;
    cin >> str;

    if(isPalindrome(str)) cout << str << "\n";
    else
    {
        int half = str.size()/2;
        string firstHalf = str.substr(0, half);
        string target = firstHalf;
        reverse(target.begin(), target.end());
        string secondHalf = str.substr(half+(str.size()%2));

        if(secondHalf <= target )
        {
            cout << firstHalf;
            if(str.size()%2 != 0) cout << str[str.size()/2];
            cout << target << "\n";
        }
        else
        {
            if(str.size() % 2 != 0) firstHalf += str[str.size()/2];

            for(int i = firstHalf.size()-1; i >= 0; --i)
            {
                if(firstHalf[i] == '9') firstHalf[i] = '0';
                else
                {
                    ++firstHalf[i];
                    break;
                }
            }
            cout << firstHalf;
            if(str.size() % 2 != 0) firstHalf.pop_back();
            reverse(firstHalf.begin(), firstHalf.end());
            cout << firstHalf << "\n";
        }
    }    
    return 0; 
}       