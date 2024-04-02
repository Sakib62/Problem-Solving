class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, ans = INT_MAX, current_or = 0;
        vector<int> last_index(32, -1);

        for (int right = 0; right < n; ++right) {
            current_or |= nums[right];

            for (int i = 0; i < 32; ++i) {
                if ((nums[right] >> i) & 1) {
                    last_index[i] = right;
                }
            }

            while (current_or >= k && left <= right) {
                ans = min(ans, right - left + 1);
                
                for (int i = 0; i < 32; i++) {
                    if (last_index[i] == left) {
                        last_index[i] = -1;
                        current_or ^= (1 << i); // int mask = ~(1 << i); current_or = current_or & mask;
                    }
                }
                ++left;
            }
        }

        return (ans != INT_MAX) ? ans : -1;
    }
};