class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        if (n <= 0) {
            return 0;
        }
        
        for (int i = 0; i < n - 1; i++) {
            tr[i + 1][0] += tr[i][0];
            tr[i + 1][tr[i + 1].size() - 1] += tr[i][tr[i].size() - 1];
            for (int j = 1; j < tr[i].size(); j++) {
                tr[i + 1][j] += min(tr[i][j - 1], tr[i][j]);
            }
        }
        
        int ans = tr[n - 1][0];
        for (int i : tr[n - 1]) {
            ans = min(ans, i);
        }
        return ans;
    }
};
