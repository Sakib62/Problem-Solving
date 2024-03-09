/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Tue__05-Mar-2024__14:27:10
 *       File    :   F_LCS.cpp
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    int sLen = s.length();
    int tLen = t.length();

    int dp[sLen][tLen];
    for (int i = 0; i < sLen; i++) {
        for (int j = 0; j < tLen; j++) {
            int cnt = (s[i] == t[j]);
            if (!i && !j) {
                dp[i][j] = cnt;
            }
            else if (!i) {
                dp[i][j] = max(dp[i][j-1], cnt);
            }
            else if (!j) {
                dp[i][j] = max(dp[i-1][j], cnt);
            }
            else {
                if (cnt) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                } 
            }
        }
    }

    // for (int i = 0; i < sLen; i++) {
    //     for (int j = 0; j < tLen; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int row = sLen - 1, col = tLen - 1;
    string ans;
    while (row >= 0 && col >= 0) {
        if (s[row] == t[col]) {
            ans += s[row];
            row--;
            col--;
            continue;
        }
        if (row == 0) {
            col--;
            continue;
        }
        if (col == 0) {
            row--;
            continue;
        }

        if (dp[row-1][col] > dp[row][col-1]) {
            row--;
        }
        else {
            col--;
        }
    }

    //cout << dp[sLen-1][tLen-1] << "\n";
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}