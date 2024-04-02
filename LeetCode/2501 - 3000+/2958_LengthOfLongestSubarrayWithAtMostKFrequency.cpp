class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mp;
        int ans = 1, st = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > k) {
                while (nums[st] != nums[i]) {
                    mp[nums[st]]--;
                    st++;
                }
                mp[nums[st]]--;
                st++;
            }
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};