int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        for (int lo = 1, hi = n; lo <= hi;) {
            int m = lo + (hi - lo) / 2;
            int g = guess(m);
            if (g == 0) return m;
            else if (g < 0) hi = m - 1;
            else lo = m + 1;
        }
        return -1;
    }
};
