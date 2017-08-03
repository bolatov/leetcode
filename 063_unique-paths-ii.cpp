class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = rows > 0 ? obstacleGrid[0].size() : 0;
        vector<vector<int>> vvi(rows, vector<int>(cols, 0));
        for (int col = 0; col < cols && obstacleGrid[0][col] != 1; col++) {
            vvi[0][col] = 1;
        }
        for (int row = 0; row < rows && obstacleGrid[row][0] != 1; row++) {
            vvi[row][0] = 1;
        }
        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                if (obstacleGrid[row][col] != 1) {
                    vvi[row][col] = vvi[row - 1][col] + vvi[row][col - 1];
                }
            }
        }
        return vvi[rows - 1][cols - 1];
    }
};
