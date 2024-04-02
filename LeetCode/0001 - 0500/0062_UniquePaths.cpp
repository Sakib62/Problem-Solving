class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        //return recur(m, n, 0, 0, dp); //top down
        //return iter(m, n, dp); //bottom up
        return iter_space_optimized(m, n); //uses 2 rows in bottom up
    }

    int recur(int m, int n, int row, int col, vector<vector<int>>& dp) {
        if(dp[row][col] != -1) return dp[row][col];
        if(col == n - 1 || row == m - 1) return dp[row][col] = 1; 
        int right = 0, down = 0;
        if(col < n - 1) right = recur(m, n, row, col+1, dp);
        if(row < m - 1) down = recur(m, n, row+1, col, dp);
        return dp[row][col] = right + down;
    }

    int iter(int m, int n, vector<vector<int>>& dp) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }

    int iter_space_optimized(int m, int n) {
        vector<vector<int>>dp(2, vector<int>(n, -1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) dp[i][j] = 1;
                else if(j == 0) dp[i%2][j] = 1;
                else dp[i%2][j] = dp[i%2][j-1] + dp[(i-1)%2][j];
            }
        }
        return dp[(m-1)%2][n-1];
    }
};
