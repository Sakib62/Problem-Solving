class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> um;
        long long cnt = 0;
        for (auto i : tasks) {
            cnt++;
            if (um.find(i) == um.end()) {
                um[i] = cnt;
            }
            else {
                if (cnt < um[i] + space + 1) cnt = um[i] + space + 1;
                um[i] = cnt;
            }
        }
        return cnt;
    }
};