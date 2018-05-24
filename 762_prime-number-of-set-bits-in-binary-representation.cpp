class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        set<int> P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int cnt = 0;
        for (; L <= R; L++) {
            int bits = 0;
            for (int i = 0; i < 32; i++) {
                bits += ((1 << i) & L) > 0;
            }
            cnt += (P.find(bits) != P.end());
        }
        return cnt;
    }
};