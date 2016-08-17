class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int p = i / 2; p < i; p++) {
                int q = i - p;
                dp[i] = max(dp[i], max(p, dp[p]) * max(q, dp[q]));
            }
        }

        return dp[n];
    }
};
