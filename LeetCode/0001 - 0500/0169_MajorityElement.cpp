class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //The intuition behind the Moore's Voting Algorithm is based on the fact that if there is a majority element in an array, it will always remain in the lead, even after encountering other elements.
        int count = 0, candidate = 0;
        for(auto i : nums) {
            if(count == 0) candidate = i;
            if(i == candidate) count++;
            else count--;
        }
        return candidate;
    }
};
