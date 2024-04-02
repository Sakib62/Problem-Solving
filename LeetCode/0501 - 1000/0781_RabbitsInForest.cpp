class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map <int, int> mp;
        int sum = 0;
        for(auto i : answers) mp[i]++; //counting occurrence for each color
        
        for(auto i : mp) {
            int group = i.second / (i.first+1);
            
            if(i.second % (i.first+1)) group++;
            
            sum += (group * (i.first+1));
        }
        return sum;
    }
};
