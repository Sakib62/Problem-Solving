/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Mon__04-Mar-2024__00:50:01
 *       File    :   A_Frog_1.cpp
**/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1), arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    dp[2] = abs(arr[1] - arr[0]);
    for (int i = 3; i <= n; i++) {
        long long one, two;
        one = dp[i-1] + abs(arr[i-1] - arr[i-2]);//0 indexed
        two = dp[i-2] + abs(arr[i-1] - arr[i-3]);
        dp[i] = min(one, two);
    }
    cout << dp[n] << "\n";
}