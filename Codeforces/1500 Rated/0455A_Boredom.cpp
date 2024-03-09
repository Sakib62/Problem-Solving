/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Sat__09-Mar-2024__10:14:32
 *       File    :   A_Boredom.cpp
**/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, mx = 0;
    cin >> n;
    unordered_map<int, int> freq;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        freq[x]++;
        mx = max(mx, x);
    }

    vector<ll> dp(mx + 1);
    dp[0] = 0;
    dp[1] = freq[1];

    for (int i = 2; i <= mx; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + (ll)freq[i] * i);
    }
    cout << dp[mx] << "\n";
}