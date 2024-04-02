/**
 *       Author :   Sakib62
 *       Created:   Sat__30.Mar.2024__03:04:56
 *       File   :   D_Wooden_Toy_Festival.cpp
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
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(all(v));
        
        int st = 0, en = (int)1e9, mid, ans = 1;
        while (st <= en) {
            mid = st + (en - st) / 2;
            int cnt = 1, tmp = v[0] + mid;
            for (int i = 1; i < n; i++) {
                if (v[i] - tmp > mid) {
                    cnt++;
                    tmp = v[i] + mid;
                }
            }
            if (cnt <= 3) {
                ans = mid;
                en = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}