class Solution {
public:    
    int fun(int n, vector<int>&dp) {
        if(dp[n] != INT_MAX) return dp[n];
        if(n == 0) return dp[0] = 0;
        
        for(int i = 1; i * i <= n; i++) {
            int val = 1 + fun(n - i * i, dp);
            dp[n] = min(dp[n], val);
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        vector <int> dp(n + 1, INT_MAX);
        return fun(n, dp);
    }
};
