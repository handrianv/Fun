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


int main()
{
    std::ios::sync_with_stdio(false);
    //cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    unordered_map<string, string> db;
    unordered_map<string, bool> logged;
    while(n--)
    {
        string type;
        cin >> type;
        if(type[0] == 'r')
        {
            string username, password;
            cin >> username >> password;
            if(db.find(username) != db.end()) cout << "fail: user already exists\n";
            else
            {
                cout << "success: new user added\n";
                db[username] = password;
            }
        }
        else if(type == "login")
        {
            string username, password;
            cin >> username >> password;
            if(db.find(username) == db.end()) cout << "fail: no such user\n";
            else if(password != db[username]) cout << "fail: incorrect password\n";
            else if(logged[username]) cout << "fail: already logged in\n";
            else
            {
                cout << "success: user logged in\n";
                logged[username] = true;
            } 
        }
        else 
        {
            string username;
            cin >> username;
            if(db.find(username) == db.end()) cout << "fail: no such user\n";
            else if(!logged[username]) cout << "fail: already logged out\n";
            else 
            {
                cout << "success: user logged out\n";
                logged[username] = false;
            }
        }
    } 
    return 0;
}   