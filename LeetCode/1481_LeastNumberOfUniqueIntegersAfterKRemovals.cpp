class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        for(auto i : arr) {
            um[i]++;
        }
        vector<pair<int, int>> vp;
        for(auto i : um) {
            vp.push_back(i);
        }
        sort(vp.begin(), vp.end(), [](auto a, auto b) {
            return a.second < b.second;
        });
        
        int count = 0;
        for(auto i : vp) {
            if(i.second <= k) {
                count++;
                k -= i.second;
            }
            else {
                break;
            }
        }
        return vp.size() - count;
    }
};
