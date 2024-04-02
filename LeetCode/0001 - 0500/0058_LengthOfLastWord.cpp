class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail = s.length() - 1, len = 0;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail--] != ' ') len++;
        return len;
    }
};