class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        if (n == 2) {
            return nums[0] == nums[1] ? 1 : 2;
        }
        vector<int> dp(n, 1);
        int prev = nums[0];
        int i = 1;
        while (i < n && nums[i] == nums[0]) i++;
        if (i >= n) return dp[n - 1];
        dp[i] = 2;
        i++;
        for (; i < n; i++) {
            if ((prev < nums[i - 1] && nums[i - 1] > nums[i]) ||
                (prev > nums[i - 1] && nums[i - 1] < nums[i])) {
                prev = nums[i - 1];
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1];
    }
};
