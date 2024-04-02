class Solution {
public:
    
    //bottom-right, cells of last row or column can be obstacle
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, -1));
        return recur(obstacleGrid, 0, 0, dp);
    }
    
    int recur(vector<vector<int>>& Grid, int row, int col, vector<vector<int>>& dp) {
        int m = Grid.size();
        int n = Grid[0].size();
        
        if(row == m || col == n) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        
        if(Grid[row][col] == 1) return dp[row][col] = 0;
        if(row == m - 1 && col == n - 1) return dp[row][col] = 1;

        return dp[row][col] = recur(Grid, row, col+1, dp) + recur(Grid, row+1, col, dp);
    }
};