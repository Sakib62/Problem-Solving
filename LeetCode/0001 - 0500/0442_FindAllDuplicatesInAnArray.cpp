class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
/*
Utilize the fact that all integers in the array are in the range [1, n]
use each element as an index to mark the corresponding element as negative.

If we encounter an element that is already negative, that means the element that made this one negative appears twice
*/

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur-1] < 0) {
                ans.push_back(cur);
            }
            else {
                nums[cur-1] *= -1;
            }
        }
        return ans;
    }
};