class Solution {
public:
//https://www.youtube.com/watch?v=vSO5ZiBk_ZM
    int missingNumber(vector<int>& nums) {
        return xorApproach(nums);
        //return sumApproach(nums);
        //return trackingApproach(nums);
        //return sortApproach(nums);
    }
    
    int xorApproach(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i <= nums.size(); i++) {
            ans = ans ^ i ^ nums[i-1];
        }
        return ans;
    }
    
    int sumApproach(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums) {
            sum += i;
        }
        int total = (nums.size() * (nums.size() + 1)) / 2;
        return total - sum;
    }
    
    int trackingApproach(vector<int>& nums) {
        vector<int> isPresent(nums.size() + 1, -1);
        for(auto i : nums) {
            isPresent[i] = 1;
        }
        int ans;
        for(int i = 0; i < isPresent.size(); i++) {
            if(isPresent[i] == -1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
    
    int sortApproach(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i != nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
};