//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        long long ans = 0;
        for(int i = 0, x, tmp; i < n; i++) {
            cin >> x;
            if(i != 0 && x < tmp) {
                ans += (tmp - x);
                x = tmp;//changed x
            }
            tmp = x;
        }
        cout << ans << "\n";
    }
}