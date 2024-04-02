class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long total = 0;
        int minInd = -1, maxInd = -1, badInd = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == minK) minInd = i;
            if (nums[i] == maxK) maxInd = i;
            if (nums[i] < minK || nums[i] > maxK) badInd = i;
            
            total += max(0, min(minInd, maxInd) - badInd);
        }
        
        return total;
    }
};