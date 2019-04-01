class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(i, dp[i]);
            for (int j = i + i; j <= n; j += i) {
                dp[j] = min(dp[j], dp[i] + 1 + (j - i) / i);
            }
        }
        return dp[n];
    }
};
