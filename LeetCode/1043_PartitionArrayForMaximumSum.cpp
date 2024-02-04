class Solution {
public:
    
    int fn(vector<int>&arr, int k, vector<int>&dp, int ind) {
        int sz = arr.size();
        if(ind >= sz) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int curMax = 0, curSum = 0, ans = 0;
        for(int i = ind; i < min(sz, ind + k); i++) {
            curMax = max(curMax, arr[i]);
            curSum = curMax * (i - ind + 1) + fn(arr, k, dp, i+1);
            ans = max(ans, curSum);
        }
        return dp[ind] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(), -1);
        return fn(arr, k, dp, 0);
    }
};
