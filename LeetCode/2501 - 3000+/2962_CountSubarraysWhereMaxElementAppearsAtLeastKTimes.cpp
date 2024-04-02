class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        for (auto i : nums) {
            mx = max(mx, i);
        }
        
        int cnt = 0, init = 0, st = 0, n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) cnt++;
            if (cnt == k) {
                while (nums[st] != mx) st++;
                ans += ((st - init + 1) * 1ll * (n - i));//if k=1, index=mid, 2.5e9
                cnt--;
                st++;
                init = st;
            }
        }
        return ans;
    }
};