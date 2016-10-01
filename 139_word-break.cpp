class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
