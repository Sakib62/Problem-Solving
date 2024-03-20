class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>mp;
        int mx = 0, cnt = 0;
        for (auto i : tasks) {
            mp[i]++;
            mx = max(mx, mp[i]);
        }
        
        for (auto i : mp) {
            if (i.second == mx) {
                cnt++;
            }
        }
        //Placing max occured char with spacing n
        //fill out the empty spaces in between
        //if many char with max freq, place them adjacent, calculate remaining slot
        //if left out slot exists, fill with idles
        int parts = mx - 1;
        int space = n - (cnt - 1);
        int empty = parts * space;
        int remains = tasks.size() - (mx * cnt);
        
        int idle = max(0, empty - remains);
        
        return tasks.size() + idle;
    }
};