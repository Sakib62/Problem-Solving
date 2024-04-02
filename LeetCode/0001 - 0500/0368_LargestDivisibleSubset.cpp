class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //take u forward -> https://www.youtube.com/watch?v=gDuZwBW9VvM
        //Longest Divisible Subsequence :3
        int n = nums.size();
        vector<int> dp(n, 1), prev(n);
        sort(nums.begin(), nums.end());
        int mx = 1, lastInd = 0;
        for(int i = 0; i < n; i++) {
            prev[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > mx) {
                mx = dp[i];
                lastInd = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastInd]);
        while(prev[lastInd] != lastInd) {
            lastInd = prev[lastInd];
            ans.push_back(nums[lastInd]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
