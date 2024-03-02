/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Fri__01-Mar-2024__17:43:25
 *       File    :   C_Equalize.cpp
**/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void fn(string a, string b) {
    int n = a.length();
    vector<int> dp(n+1);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + (a[i-1] != b[i-1]);
        if (i >= 2 and a[i-1] != a[i-2] and a[i-1] == b[i-2] and b[i-1] == a[i-2]) {
            dp[i] = min(dp[i], dp[i-2] + 1);
        }
    }
    cout << dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int diff = 0, adj = 0, last = -2;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            diff++;
            bool used = false;
            if (i - last == 1 && a[i] != a[i-1]) {
                adj++;
                used = true;
            }
            if(!used) last = i;
        }
    }
    cout << diff - adj << "\n";
}