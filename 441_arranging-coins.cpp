class Solution {
public:
    int arrangeCoins(int n) {
        long long ans = 0;
        long long lo = 1, hi = n;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long coins = mid * (mid + 1) / 2;
            if (coins == n) {
                ans = mid;
                break;
            } else if (coins > n) {
                hi = mid - 1;
            } else {
                ans = max(ans, mid);
                lo = mid + 1;
            }
            // printf("mid=%lld coins=%lld ans=%d\n", mid, coins, ans);
        }
        return ans;
    }
};
