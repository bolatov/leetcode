class Solution {
public:
    int numTrees(int n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
            dp[i] *= 2;
            if (i % 2) {
                int mid = (i / 2);
                dp[i] += dp[mid] * dp[mid];
            }
        }
        return dp[n];
    }
};
