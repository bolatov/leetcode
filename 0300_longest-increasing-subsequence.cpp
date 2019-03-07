class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] > dp[i]) {
                    dp[i] = dp[j];
                    
                }
            }
            dp[i]++;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
