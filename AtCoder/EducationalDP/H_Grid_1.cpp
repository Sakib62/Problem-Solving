/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Mon__04-Mar-2024__01:18:48
 *       File    :   H_Grid_1.cpp
**/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, mod = 1e9 + 7;
    cin >> m >> n;
    char grid[m][n];
    int dp[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0) {
                dp[i][j] = 1;//not blocked
            }
            else if (i == 0) {
                dp[i][j] = dp[i][j-1];//prev might be blocked
            }
            else if (j == 0) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout << dp[m-1][n-1] << "\n";
}