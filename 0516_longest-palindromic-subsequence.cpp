class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        
        int len = s.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= len; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[len][len];
    }
};
