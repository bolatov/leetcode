// 156ms
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1);
        for (int i = 1; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[pairs.size() - 1];
    }
};

// 92ms
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<pair<int, int>> vbe(n);
        vector<pair<int, int>> ven(n);
        for (int i = 0; i < n; i++) {
            vbe[i] = {pairs[i][0], i};
            ven[i] = {pairs[i][1], i};
        }
        sort(vbe.begin(), vbe.end());
        sort(ven.begin(), ven.end());
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int c = vbe[i].first;
            int pos = vbe[i].second;
            int idx = -1;
            int lo = 0, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int b = ven[mid].first;
                if (b < c) {
                    idx = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            int len = 0;
            for (int j = 0; j <= idx; j++) {
                len = max(len, dp[ven[j].second]);
            }
            dp[pos] += len;
            ans = max(ans, dp[pos]);
        }
        return ans;
    }
};
