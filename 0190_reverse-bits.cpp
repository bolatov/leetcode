class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int sz = sizeof(n) * CHAR_BIT;
        uint32_t m = 0;
        for (int i = 0, j = sz - 1; i < sz && j >= 0; i++, j--) {
            if (n & (1 << i)) {
                m |= (1 << j);
            }
        }
        return m;
    }
};
