class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        long long ans = 0;
        for(int i = min(startPos[0], homePos[0]); i <= max(startPos[0], homePos[0]); i++) {
            ans += rowCosts[i];
        }
        for(int i = min(startPos[1], homePos[1]); i <= max(startPos[1], homePos[1]); i++) {
            ans += colCosts[i];
        }
        return ans - rowCosts[startPos[0]] - colCosts[startPos[1]];
    }
};