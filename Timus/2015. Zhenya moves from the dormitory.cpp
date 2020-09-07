/*
    I'm not proud of this implementation :(
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

// Return {max adv, idx}
pi LiveAlone(const vector<pair<pi, int>>& houses, int money)
{
    pi ans(-1, -1);
    for(int i = 0; i < (int)houses.size(); ++i)
    {
        auto house = houses[i];
        if(house.first.first <= money && house.first.second > ans.first) ans = {house.first.second, house.second+1};
    }
    return ans;
}

// {max adv, house idx, friend idx}
tuple<int, int, int> LiveTogether(const vector<pair<pi, int>>& houses, const vector<pi>& friends, int money)
{
    tuple<int, int, int> ans(-1, -1, -1);
    for(int i = 0; i < (int)houses.size(); ++i)
    {
        auto house = houses[i];
        int half = house.first.first / 2 + (house.first.first % 2 != 0);
        if(money < half) continue;

        for(int j = 0; j < (int)friends.size(); ++j)
        {
            pi f = friends[j];
            //cout << "comparing price " << half << " with money " << f.first << "\n";
            if(f.first < half) continue;
            if(house.first.second + f.second > get<0>(ans))
            {
                ans = {house.first.second + f.second, house.second+1, j+1};
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int money, adv1, adv2, n;
    cin >> money >> adv1 >> adv2 >> n;
    vector<pi> friends(n); // {money, adv}
    for(auto& v : friends)
    {
        cin >> v.first >> v.second;
    }
    int m;
    cin >> m;
    vector<pair<pi, int>> firstType, secondType; // {{price, adv}, idx}
    for(int i = 0; i < m; ++i)
    {
        int type, price, adv;
        cin >> type >> price >> adv;
        (type == 1) ? firstType.push_back({{price, adv}, i}) : secondType.push_back({{price, adv}, i});
    }

    int ansType = -1;
    pi ansAlone(-1, -1);

    pi alone1 = LiveAlone(firstType, money);
    if(alone1.first > -1)
    {
        ansAlone = {alone1.first + adv1, alone1.second};
        ansType = 1;
    }
    pi alone2 = LiveAlone(secondType, money);
    if(alone2.first > -1 && alone2.first + adv2 > ansAlone.first)
    {
        ansAlone = {alone2.first + adv2, alone2.second};
        ansType = 2;
    } 
    
    auto ansTogether = LiveTogether(secondType, friends, money);
    if(get<0>(ansTogether) > -1 && get<0>(ansTogether) > ansAlone.first)
    {
        ansType = 3;
    }
    
    if(ansType == -1)
    {
        cout << "Forget about apartments. Live in the dormitory.\n";
    }
    else if(ansType == 1 || ansType == 2)
    {
        cout << "You should rent the apartment #" << ansAlone.second << " alone.\n";
    }
    else
    {
        cout << "You should rent the apartment #" << get<1>(ansTogether) << " with the friend #" << get<2>(ansTogether) << ".\n";
    }
    
    return 0;
}
 
/*
 
*/  