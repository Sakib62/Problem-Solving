class Solution {
public:
    string minWindow(string s, string t) {
        int tl = t.size();
        int sl = s.size();
        
        unordered_map<char, int>mp1, mp2;
        for(char c : t) mp1[c]++;
        int ansInd = -1, ansLen = INT_MAX, count = 0, init = 0;
        
        for(int i = 0; i < sl; i++) {
            char tmp = s[i];
            mp2[tmp]++;
            if(mp2[tmp] <= mp1[tmp]) {
                count++;
            }
            if(count == tl) {
                char po = s[init];
                while(mp2[po] > mp1[po]) {
                    mp2[po]--;
                    init++;
                    po = s[init];
                }
                int curLen = i - init + 1;
                if(ansLen > curLen) {
                    ansLen = curLen;
                    ansInd = init;
                }
            }
        }
        if(ansInd == -1) return "";
        else return s.substr(ansInd, ansLen);
    }
};
