class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //return indexAsHashKey(nums);
        return cycleSort(nums);
    }
    
    int cycleSort(vector<int>& nums) {
        int n = nums.size();
        //Put each element at the index that corresponds to its value
        for (int i = 0; i < n; i++) {
            //swap till element is placed accordingly for current index
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i+1;
            }
        }
        
        return n+1;
    }
    
    int indexAsHashKey(vector<int>& nums) {
        bool one = false;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                one = true;
            }
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        
        if (!one) return 1;
        
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if (nums[x-1] > 0) nums[x-1] *= -1; //only once, even for duplicates
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }
        
        return n+1;
    }
};