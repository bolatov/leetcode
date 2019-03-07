// 12 ms
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = rows > 0 ? grid[0].size() : 0;
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        int islands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '0' || used[i][j]) continue;
                islands++;
                q.push({i, j});
                used[i][j] = true;
                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    // east
                    if (p.second + 1 < cols && grid[p.first][p.second + 1] == '1' && !used[p.first][p.second + 1]) {
                        q.push({p.first, p.second + 1});
                        used[p.first][p.second + 1] = true;
                    }
                    
                    // south
                    if (p.first + 1 < rows && grid[p.first + 1][p.second] == '1' && !used[p.first + 1][p.second]) {
                        q.push({p.first + 1, p.second});
                        used[p.first + 1][p.second] = true;
                    }
                    
                    // west
                    if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == '1' && !used[p.first][p.second - 1]) {
                        q.push({p.first, p.second - 1});
                        used[p.first][p.second - 1] = true;
                    }
                    
                    // north
                    if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == '1' && !used[p.first - 1][p.second]) {
                        q.push({p.first - 1, p.second});
                        used[p.first - 1][p.second] = true;
                    }
                }
            }
        }
        return islands;
    }
};

// 13 ms
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
