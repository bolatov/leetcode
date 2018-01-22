class Solution {
private:
    void expand(vector<vector<char>>& grid, vector<vector<bool>>& u, int i, int j) {
        u[i][j] = true;
        // south
        if (i + 1 < grid.size() && grid[i + 1][j] == '1' && !u[i + 1][j]) expand(grid, u, i + 1, j);
        
        // west
        if (j - 1 >= 0 && grid[i][j - 1] == '1' && !u[i][j - 1]) expand(grid, u, i, j - 1);
        
        // north
        if (i - 1 >= 0 && grid[i - 1][j] == '1' && !u[i - 1][j]) expand(grid, u, i - 1, j);
        
        // east
        if (j + 1 < grid[i].size() && grid[i][j + 1] == '1') expand(grid, u, i, j + 1);
    }
public:    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid.empty() ? 0 : grid[0].size();
        vector<vector<bool>> u(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !u[i][j]) {
                    expand(grid, u, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
