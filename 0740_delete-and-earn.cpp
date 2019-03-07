class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10000 + 1;
        vector<int> buckets(n, 0);
        for (int i : nums) {
            buckets[i]++;
        }
        
        vector<int> dp(n, 0);
        dp[n-2] = buckets[n-2] * (n-2);
        dp[n-1] = buckets[n-1] * (n-1);
        for (int i = n-3; i >= 0; i--) {
            dp[i] = max(i*buckets[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};
