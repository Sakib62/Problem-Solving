/**
 *       Author :   Sakib62
 *       Created:   Mon__01.Apr.2024__17:20:47
 *       File   :   C_Delete_Two_Elements.cpp
**/
//Bismillahir Rahman-ir Rahim
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
    for (int TC = 1; TC <= testCase; TC++) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> mp;

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]]++;
            sum += v[i];
        }

        sum *= 2;
        if (sum % n) {
            cout << "0\n";
            continue;
        }

        long long avg = sum / n;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (mp.find(avg - v[i]) != mp.end()) {
                int tmp = mp[avg - v[i]];
                if (v[i] == avg - v[i]) tmp--;
                ans += tmp;
            }
        }
        cout << ans / 2 << "\n";
    }
}