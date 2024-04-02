class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
            
        do {
            slow = square(slow);
            fast = square(square(fast));
        } while (slow != fast && fast != 1);
        
        return fast == 1;
    }
    
    int square(int num) {
        int ans = 0;
        while (num) {
            int rem = num % 10;
            ans += (rem * rem);
            num /= 10;
        }
        return ans;
    }
};