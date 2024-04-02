/**
 *       Author :   Sakib62
 *       Created:   Thu__28.Mar.2024__03:26:10
 *       File   :   C_LR_remainders.cpp
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
        int n, m, mul = 1;
        cin >> n >> m;
        vector<int> v(n), ans;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        string s;
        cin >> s;
        int l = 0, r = n - 1;
        for (auto i : s) {
            if (l == r) break;
            if (i == 'L') {
                l++;
            }
            else {
                r--;
            }
        }

        int fin = v[l] % m;
        ans.push_back(fin);

        for (int i = n-2; i >= 0; i--) {
            if (s[i] == 'R') {
                r++;
                fin = (fin * (v[r] % m)) % m;
            }
            else {
                l--;
                fin = (fin * (v[l] % m)) % m;
            }
            ans.push_back(fin);
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}