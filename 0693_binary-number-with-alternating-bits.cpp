class Solution {
public:
    int highestBit(int n) {
        if (n <= 0) {
            return -1;
        }
        int i;
        for (i = 31; i >= 0; i--) {
            if ((1 << i) & n) return i;
        }
        return i;
    }
    bool hasAlternatingBits(int n) {
        int hi = highestBit(n);
        for (int i = 1; i <= hi; i++) {
            bool prev = (1 << (i - 1)) & n;
            bool cur = (1 << i) & n;
            if (prev == cur) return false;
        }
        return true;
    }
};