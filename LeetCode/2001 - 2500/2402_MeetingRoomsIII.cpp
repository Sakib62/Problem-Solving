class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        vector<int>room(n, 0);
        vector<long long>at(n, 0);
        sort(m.begin(), m.end());
        
        for(int i = 0; i < m.size(); i++) {
            int unused = -1, nearest = -1;
            long long mnTime = LLONG_MAX;
            
            for(int j = 0; j < n; j++) {
                if(at[j] <= m[i][0]) {
                    unused = j;
                    break;
                }
                 if(mnTime > at[j]) {
                     mnTime = at[j];
                     nearest = j;
                 }
            }
            
            if(unused != -1) {
                room[unused]++;
                at[unused] = m[i][1];
            }
            else {
                room[nearest]++;
                at[nearest] += (m[i][1] - m[i][0]);
            }
        }
        
        int ans = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            if(room[i] > mx) {
                ans = i;
                mx = room[i];
            }
        }
        
        return ans;
    }
};