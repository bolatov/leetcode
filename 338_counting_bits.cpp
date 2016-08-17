class Solution {
public:
    /**
     * Suffixes of numbers in bitwise representation are repeated.
     * Calculate for the initial ('00', '01', '10', '11') and
     * infer the rest from already computed values.
     * 
     * e.g. count bits for n = 19 = 10011b,
     *      by subtracting the nearest power of two (16) from 19
     *      will result in 3 ('11').
     */
    vector<int> countBits(int num) {
        vector<int> v(num + 1, 0);
        int pwr = 0;
        for (int i = 1; i <= num; i++) {
            if (i && (i & (i-1)) == 0) pwr = i;
            if (i == 1 || i == 2) v[i] = 1;
            else if (i == 3)      v[i] = 2;
            else {
                v[i] = v[i - pwr] + 1;
            }
        }
        return v;
    }
};
