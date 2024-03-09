/**	  	 بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
 *       Author  :   Sakib62
 *       Created :   Fri__08-Mar-2024__12:42:02
 *       File    :   D_Knapsack_1.cpp
**/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll recur(int i, int j, vector<int>& wt, vector<int>& val, vector<vector<ll>>& dp) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (dp[i][j]) {
        return dp[i][j];
    }
    if (wt[i] > j) {
        dp[i][j] = recur(i-1, j, wt, val, dp);
    }
    else {
        dp[i][j] = max(recur(i-1, j, wt, val, dp), val[i] + recur(i-1, j-wt[i], wt, val, dp));
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, W;
    cin >> N >> W;

    vector<int> wt(N+1), val(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> wt[i] >> val[i];
    }

    vector<vector<ll>> dp;
    dp.resize(N+1, vector<ll>(W+1, 0));

    //cout << recur(N, W, wt, val, dp) << "\n";

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i] > w) {
                dp[i][w] = dp[i-1][w];  
            }
            else {
                dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w-wt[i]]);
            }
        }
    }
    cout << dp[N][W] << "\n";
}