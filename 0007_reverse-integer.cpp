class Solution {
public:
    int reverse(int x) {
        bool isNegative = 0;
        if (x < 0) {
            isNegative = 1;
            x *= -1;
        }
        long long n = 0L;
        while (x) {
            n *= 10;
            n += x % 10;
            x /= 10;
        }
        
        n = (isNegative ? -n : n);
        if (n > INT_MAX || n < INT_MIN) return 0;
        return n;
    }
};
