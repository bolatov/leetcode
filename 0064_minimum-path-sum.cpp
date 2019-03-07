class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows > 0 ? grid[0].size() : 0;
        vector<vector<int>> m(rows, vector<int>(cols, -1));
        m[0][0] = grid[0][0];
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row + 1 < rows && (m[row][col] + grid[row + 1][col] < m[row + 1][col] || m[row + 1][col] < 0)) {
                    m[row + 1][col] = m[row][col] + grid[row + 1][col];
                }
                if (col + 1 < cols && (m[row][col] + grid[row][col + 1] < m[row][col + 1] || m[row][col + 1] < 0)) {
                    m[row][col + 1] = m[row][col] + grid[row][col + 1];
                }
            }
        }
        return m[rows - 1][cols - 1];
    }
};
