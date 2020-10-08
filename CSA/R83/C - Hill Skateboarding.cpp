/*
    We must start the journey from a downhill part, denoted "-1" in this problem.
    Let's index the array 0-based. If we start from "-1" at index i, and the rightmost we can get to is index j.
    Then for any "-1" on index i < k <= j, the rightmost we can get will not be more to the right than j.

    For example, if we have:
    -1 1 -1 1 0 ....
    If we start from the first "-1" at index 0, we can get as far as index 4. Then we know if we start from "-1" at index 0 < k < 4, the farthest we can get won't exceed index 4.
    
    Proof: We note that how much to the right we can get depends on our starting speed. If we start from "-1" on index k, our starting speed is 0. If we start from index i, we know that the rightmost we can get is index j >= k. 
    So when we end up in index k starting from i, our speed must be at least 0 or even greater, which means we can get at least as far, if not farther, if we start form index i.

    With this observation the rest is just simple sliding window.
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
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto& v : vec)
    {
        cin >> v;
    }

    int left = 0, right = 0;
    double ans = 0;
    while(left < n && right < n)
    {
        if(vec[left] != -1)
        {
            ++left; ++right; 
            continue;
        }

        int speed = 0; // Speed before starting this part
        do {
            if(vec[right] == -1)
            {
                speed += 2;
            }
            else if(vec[right] == 0)
            {
                --speed;
            }
            else
            {
                speed -= 2;
            }
            //cout << "now speed " << speed << "\n";
            ++right;           
        } while( (speed > 0 && right < n) || (speed == 0 && right < n && vec[right] == -1)); // If speed is 0 but we're starting downhill part, we can continue

        double traveled = right-left;
        if(speed == -1) traveled -= 0.5;
        ans = max(ans, traveled);
        left = right;
    }
    cout << ans << "\n";
    return 0;
}
 
/*
 
*/ 