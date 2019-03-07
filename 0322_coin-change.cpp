class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        long long sz = ((long long) amount) + 1LL;
        vector<int> dp(sz, -1);
        sort(coins.begin(), coins.end());
        for (int i : coins) {
            if (i > amount) {
                break;
            }
            dp[i] = 1;
        }
        for (long long i = coins[0]; i < sz; i++) {
            // unreachable amount
            if (dp[i] < 0) {
                continue;
            }
            for (long long coin : coins) {
                if (i + coin > (long long) amount) {
                    break;
                }
                if (dp[i + coin] < 0 || dp[i] + 1 < dp[i + coin]) {
                    dp[i + coin] = dp[i] + 1;
                }
            }
        }
        return dp[amount];
    }
};
