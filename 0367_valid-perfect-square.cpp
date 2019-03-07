class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 1, hi = num;
        while (lo <= hi) {
            long long mi = lo + (hi - lo) / 2;
            long long sq = mi * mi;
            if (sq == num) return true;
            else if (sq > num) hi = mi - 1;
            else lo = mi + 1;
        }
        return false;
    }
};
