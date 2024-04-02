class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1, score = 0;
        
        //use low valued token to gain score
        //use score to gain high value token
        
        while (l < r) {
            //cout << power << " " << score << " " << l << " " << r << "\n";
            if (power >= tokens[l]) {
                score++;
                power -= tokens[l];
                l++;
                continue;
            }
            
            if (score) {
                int tmp = power + tokens[r];
                if (tmp >= tokens[l]) {
                    power = tmp;
                    r--;
                    score--;
                }
            }
            else {
                break;
            }
        }
        
        if (l == r and power >= tokens[l]) {
            score++;
        }
        
        return score;
    }
};