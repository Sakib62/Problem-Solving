class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        
        int ans = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++) {
            ans = min(ans, recur(grid, 0, i, dp, moveCost));
        }
        return ans;
    }
    
    int recur(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp, vector<vector<int>>& moveCost) {
        if(dp[row][col] != INT_MAX) return dp[row][col];
        if(row == grid.size() - 1) return dp[row][col] = grid[row][col];
        
        int ans = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++) {
            ans = min(ans, moveCost[grid[row][col]][i] + recur(grid, row+1, i, dp, moveCost));
        }
        return dp[row][col] = ans + grid[row][col];
    }
};