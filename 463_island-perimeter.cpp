class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int m = grid[0].size();
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    sum += (i - 1 < 0 || grid[i - 1][j] == 0);
                    sum += (j + 1 >= m || grid[i][j + 1] == 0);
                    sum += (i + 1 >= n || grid[i + 1][j] == 0);
                    sum += (j - 1 < 0 || grid[i][j - 1] == 0);
                }
            }
        }
        return sum;
    }
};