class Solution {
public:
    int mySqrt(int x) {
        long lo = 1, hi = INT_MAX;
        int ans = 0;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2L;
            long mm = mid * mid;
            
            // printf("lo=%ld hi=%ld mid=%ld mm=%ld\n", lo, hi, mid, mm);
            if (mm == x) {
                return mid;
            } else if (mm > x) {
                hi = mid - 1L;
            } else {
                lo = mid + 1L;
                ans = mid;
            }
        }
        return ans;
    }
};
