//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        string s;
        cin >> s;
        int ans = 1, mx = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) ans++;
            else ans = 1;
            mx = max(ans, mx);
        }
        cout << mx << "\n";
    }
}