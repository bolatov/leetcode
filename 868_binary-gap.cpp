class Solution {
public:
    int binaryGap(int N) {
        int k = 1000;
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & N) {
                ans = max(i - k, ans);
                k = i;
            }
        }
        return max(0, ans);
    }
};
