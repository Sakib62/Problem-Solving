// Problem: Restaurant Customers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1619
// Parsed at: 2022-11-13 20:12:40
// Memory Limit: 512 MB
// Time Limit: 1000 ms

// Bismillahir Rahmanir Rahim
// Author: Sakib62
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << ">" << #x << ": " << x << "\n"; 
#define all(c) c.begin(), c.end()
#define revall(c) c.rbegin(), c.rend()
#define F first
#define S second

typedef unsigned long long ull;
typedef long long ll;

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;

    cin >> testCase;
    vector <pair<int, int> > serial;
    while(testCase--) {
        int n, m;
        cin >> n >> m;
        serial.push_back({n, 1});//arrival time
        serial.push_back({m, 2});//departure time
    }
    sort(all(serial));
    int cnt = 0, mx = 0;
    for(auto i : serial) {
        if(i.second == 1) cnt++;
        else cnt--;
        mx = max(mx, cnt);
    }
    cout << mx << "\n";
}