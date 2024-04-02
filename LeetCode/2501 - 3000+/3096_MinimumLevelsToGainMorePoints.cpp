class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n = p.size();
        
        vector<int> z(n), o(n);
        if (p[0] == 0) {
            z[0] = 1;
            o[0] = 0;
        }
        else {
            z[0] = 0;
            o[0] = 1;
        }
        
        for (int i = 1; i < n; i++) {
            if (p[i] == 0) {
                z[i] = z[i-1] + 1;
                o[i] = o[i-1];
            }
            else {
                z[i] = z[i-1];
                o[i] = o[i-1] + 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            int ff = o[i] - z[i];
            int ss = (o[n-1] - o[i]) - (z[n-1] - z[i]);
            if (ff > ss && i != n-1) return i+1;
        }
        return -1;
    }
};