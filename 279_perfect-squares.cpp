class Solution {
public:
    int numSquares(int n) {
        if (n < 4) {
            return n;
        }
        vector<int> vi = {1};
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 1;
        for (int i = 2; i * i <= n; i++) {
            vi.push_back(i * i);
            dp[i * i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j : vi) {
                if (i + j > n) {
                    break;
                }
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        
        return dp[n];
    }
};
