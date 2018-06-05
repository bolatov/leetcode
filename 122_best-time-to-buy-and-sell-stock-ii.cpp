class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int be = -1;
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i - 1]) {
                be = (be >= 0) ? be : i - 1;
            } else {
                ans += (be >= 0) ? prices[i - 1] - prices[be] : 0;
                be = -1;
            }
            // printf("i=%d ans=%d\n", i, ans);
        }
        ans += be >= 0 ? prices[prices.size() - 1] - prices[be] : 0;
        // printf("be=%d ans=%d\n", be, ans);
        return ans;
    }
};
