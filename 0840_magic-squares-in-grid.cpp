class Solution {
public:
    bool check(vector<vector<int>>& grid, int n, int m) {
        for (int i = n - 2; i <= n; i++) {
            for (int j = m - 2; j <= m; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9) {
                    return false;
                }
            }
        }
        vector<int> vi;
        for (int i = n - 2; i <= n; i++) {
            vi.push_back(grid[i][m - 2] + grid[i][m - 1] + grid[i][m]);
        }
        for (int j = m - 2; j <= m; j++) {
            vi.push_back(grid[n - 2][j] + grid[n - 1][j] + grid[n][j]);
        }
        vi.push_back(grid[n - 2][m - 2] + grid[n - 1][m - 1] + grid[n][m]);
        vi.push_back(grid[n - 2][m] + grid[n - 1][m - 1] + grid[n][m - 2]);
        for (int i = 1; i < vi.size(); i++) {
            if (vi[i] != vi[i - 1]) {
                return false;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 2; i < grid.size(); i++) {
            for (int j = 2; j < grid[0].size(); j++) {
                ans += check(grid, i, j);
            }
        }
        return ans;
    }
};
