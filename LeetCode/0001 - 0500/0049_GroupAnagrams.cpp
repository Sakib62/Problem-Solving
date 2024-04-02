class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mp;
        for(auto i : strs) {
            auto tmp = i;
            sort(i.begin(), i.end());
            mp[i].push_back(tmp);
        }
        vector < vector < string > > lol;
        for(auto i : mp) {
            lol.push_back(i.second);
        }
        return lol;
    }
};
