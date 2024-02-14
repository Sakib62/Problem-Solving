class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        //return fn(grid, 0, 0, dp); //Top Down
        //return fn2(grid); //Bottom Up
        return fn3(grid); //Bottom Up - Space optimized
    }
    
    //Recursive Version
    int fn(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if(dp[row][col] != INT_MAX) return dp[row][col];
        
        int m = grid.size();
        int n = grid[0].size();
        if(row == m - 1 && col == n - 1) return dp[row][col] = grid[row][col];
        
        int right, down;
        right = down = INT_MAX;
        
        if(col+1 < n) right = fn(grid, row, col+1, dp);
        if(row+1 < m) down = fn(grid, row+1, col, dp);
        
        return dp[row][col] = grid[row][col] + min(right, down); 
    }
    
    //Iterative Version
    int fn2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int prev = 0;
                if(i == 0) prev = dp[i][j-1];
                else if(j == 0) prev = dp[i-1][j];
                else prev = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = prev + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
    
    //Iterative Space Optimized
    int fn3(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //As we are using only the previous row to calculate for current row
        vector <vector <int> > dp(2, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int prev = 0;
                if(i == 0) prev = dp[i%2][j-1]; 
                else if(j == 0) prev = dp[(i-1)%2][j];
                else prev = min(dp[(i-1)%2][j], dp[i%2][j-1]);
                
                dp[i%2][j] = prev + grid[i][j];
            }
        }
        return dp[(m-1)%2][n-1];
    }
};
