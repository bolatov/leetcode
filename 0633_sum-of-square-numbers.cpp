class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 0) return true;
        for (long a = 1; a <= c; a++) {
            long aa = a * a;
            long bb = c - aa;
            if (bb < 0) {
                return false;
            }
            long b = sqrt(bb);
            if (aa + b * b == c) return true;
        }
        return false;
    }
};
