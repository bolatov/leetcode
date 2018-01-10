class Solution {
// source: https://leetcode.com/problems/guess-number-higher-or-lower-ii/discuss/84762/
public:
    int dp(int start, int end, auto& memo) {
        if (start >= end) {
            return 0;
        }
        
        int len = end - start + 1;
        if (len == 2) {
            return start;
        } 
        
        int minCost = INT_MAX;
        for (int k = start; k <= end; k++) {
            int left  = (memo[start][k - 1] >= 0) ? memo[start][k - 1] : dp(start, k - 1, memo);
            int right = (memo[k + 1][end] >= 0)   ? memo[k + 1][end]   : dp(k + 1, end, memo);
            int cost = k + max(left, right);
            if (cost < minCost) {
                minCost = cost;
            }

            memo[start][k - 1] = left;
            memo[k + 1][end]   = right;
        }
        return minCost;
    }
    int getMoneyAmount(int n) {
        int sz = n + 2;
        vector<vector<int>> memo(sz, vector<int>(sz, -1));
        return dp(1, n, memo);
    }
};
