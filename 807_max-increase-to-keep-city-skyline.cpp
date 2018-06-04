class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> vr(n, 0), vc(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vr[i] = max(vr[i], grid[i][j]);
                vc[j] = max(vc[j], grid[i][j]);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += min(vr[i], vc[j]) - grid[i][j];
            }
        }
        return sum;
    }
};
