class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return 1;
        if (num != 1 && (num & (num-1)) == 0) {
            for (int i = 0; i < 32; i++) {
                if ((num & 1 << i) && i % 2 == 0) return 1;
            }
        }
        return 0;
    }
};
