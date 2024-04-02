/**
 *       Author :   Sakib62
 *       Created:   Fri__29.Mar.2024__04:06:25
 *       File   :   D_Ice_Cream_Balls.cpp
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
        ll n;
        cin >> n;
        ll st = 2, en = (ll)2e9, mid, ans = 1, tmp;

        while (st < en) {
            mid = st + (en - st) / 2;
            tmp = (mid * (mid - 1)) / 2;
            if (tmp == n) {
                ans = mid;
                break;
            }
            if (tmp > n) {
                en = mid;
            }
            else {
                st = mid + 1;
                ans = mid;
            }
        }

        ll cur = (ans * (ans - 1)) / 2;
        cout << ans + n - cur << "\n";
    }
}