//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        int ans = n;
        for(int i = 1, x; i < n; i++) {
            cin >> x;
            ans ^= x;//Using XOr property to find missing number from 1 to n.
            ans ^= i;//All numbers are xor'ed twice, so they become zero, we are left with the missing number.
        }
        cout << ans << "\n";
    }
}