class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int n = prices.size();
        vector<int> v(n, 0);
        int rmx = prices[n-1];
        v[n-1] = rmx;
        for (int i = n-2; i >= 0; i--) {
            v[i] = rmx;
            rmx = max(rmx, prices[i]);
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(v[i] - prices[i], mx);
        }
        return mx;
    }
};
