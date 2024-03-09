/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Thu__07-Mar-2024__17:54:16
 *       File    :   C_Basketball_Exercise.cpp
**/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


ll recur(vector<vector<ll>>& dp, vector<int>& a, vector<int>& b, int ind, int ops) {
    if (ind == -1) {
        return 0;
    }
    if (dp[ind][ops] != -1) {
        return dp[ind][ops];
    }

    ll one = 0, two = 0, three = 0;
    if (ops != 1) {
        one = a[ind] + recur(dp, a, b, ind-1, 1);
    }
    if (ops != 2 ) {
        two = b[ind] + recur(dp, a, b, ind-1, 2); 
    }
    three = recur(dp, a, b, ind-1, ops);

    return dp[ind][ops] = max(one, max(two, three));
}

ll iter(vector<int>& a, vector<int>& b) {
    int n = a.size();
    n--;

    ll dp[n+1][2];
    dp[1][0] = a[1];
    dp[1][1] = b[1];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(a[i]+dp[i-1][1], dp[i-1][0]);
        dp[i][1] = max(b[i]+dp[i-1][0], dp[i-1][1]);
    }

    return max(dp[n][0], dp[n][1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(3, -1));

    //cout << recur(dp, a, b, n, 0);
    cout << iter(a, b);
}