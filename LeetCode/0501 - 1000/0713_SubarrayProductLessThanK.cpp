class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int st = 0, tmp = 1, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp *= nums[i];
            while (tmp >= k && st <= i) {
                tmp /= nums[st];
                st++;//min index st such that from mul of nums[st] to nums[i] < k 
            }
            ans += (i - st + 1); //subarrays ending at i
        }
        return ans;
    }
};
//right - left + 1 gives us the count of all subarrays ending at the current right position