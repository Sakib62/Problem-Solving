class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //hare and tortoise - floyd cycle algorithm
        auto slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};