/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Fri__08-Mar-2024__12:08:25
 *       File    :   A_Cut_Ribbon.cpp
**/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (i >= a) {
            dp[i] = max(dp[i], 1 + dp[i - a]);
        }
        if (i >= b) {
            dp[i] = max(dp[i], 1 + dp[i - b]);
        }
        if(i >= c) {
            dp[i] = max(dp[i], 1 + dp[i - c]);
        }
    }
    cout << dp[n] << "\n";
}