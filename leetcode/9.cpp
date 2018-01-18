class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;
    
        int half_sum = 0;
        while (x > half_sum) {
            half_sum = half_sum * 10 + x % 10;
            x /= 10;
        }
        return (half_sum == x) || (half_sum / 10 == x);
    }
};
