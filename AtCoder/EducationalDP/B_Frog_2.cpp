/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Mon__04-Mar-2024__00:57:55
 *       File    :   B_Frog_2.cpp
**/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n), dp(n + 1, INT_MAX);
    for (auto &i : a) {
        cin >> i;
    }

    dp[0] = dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= i + k and j <= n; j++) {
            dp[j] = min(dp[j], dp[i] + abs(a[j-1] - a[i-1])); 
        }
    }
    //push dp, in which j , does i contribute to. push contribution

    cout << dp[n] << "\n";
}