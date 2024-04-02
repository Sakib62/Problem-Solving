class Solution {
public:
int countSubstrings(string s) {
	int n = size(s), cnt = n;
	//Odd length palindromes
    int l = 0, r = 2;
    //worst case if all char are same
	for(int i = 1; i < n; i++, l = i - 1, r = i + 1) {
        while(l >= 0 && r < n && s[l] == s[r]) {//expand around current palindrome
            l--, r++, cnt++;
        }
    }                    
	//Even length palindromes
    l = 0, r = 1;
	for(int i = 1; i < n; i++, l = i - 1, r = i) {
        while(l >= 0 && r < n && s[l] == s[r]) {
            l--, r++, cnt++;
        }
    }       
	return cnt;
}
};
