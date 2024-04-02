class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        return hareAndTortoise(nums);
        //return cycleSortIdea(nums);//this one modifies the array though but cool approach
    }
    
    int hareAndTortoise(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        slow = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    
    int cycleSortIdea(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            if (nums[x-1] < 0) {
                return x;
            }
            nums[x-1] *= -1;
        }
        return 0;
    }
};