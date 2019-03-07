class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int hi = -1;
		    // get highest bit
        for (int i = 31; i >= 0; --i) {
            if (n & (1 << i)) {
                hi = i;
                break;
            }
        }
        int r = 0;
		    // calculate same prefixes
        for (; hi >= 0 && ((m & (1 << hi)) == (n & (1 << hi))); hi--) {
            if ((m & (1 << hi))) {
                r |= 1 << hi;
            }
        }
        return r;
    }
};
