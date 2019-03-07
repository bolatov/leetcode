class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(n, vector<int>(m, 1));
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                v[i][j] = v[i - 1][j] + v[i][j - 1];
        return v[n - 1][m - 1];
    }
};