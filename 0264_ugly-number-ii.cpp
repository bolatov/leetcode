class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;
        for (int i = 1; i < n; i++) {
            ugly[i] = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            if (ugly[i] == nextMultipleOf2) {
                i2++;
                nextMultipleOf2 = ugly[i2] * 2;
            }
            if (ugly[i] == nextMultipleOf3) {
                i3++;
                nextMultipleOf3 = ugly[i3] * 3;
            }
            if (ugly[i] == nextMultipleOf5) {
                i5++;
                nextMultipleOf5 = ugly[i5] * 5;
            }
            // printf("%d: %d\n", i, ugly[i]);
        }
        return ugly[n - 1];
    }
};
