/*
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
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

bool Lucky(int num)
{
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 6; ++i)
    {
        int curr = num % 10;
        (i < 3) ? sum1 += curr : sum2 += curr;
        num /= 10;
    }
    return (sum1 == sum2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int num;
    cin >> num;
    (Lucky(num+1) || Lucky(num-1)) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}   