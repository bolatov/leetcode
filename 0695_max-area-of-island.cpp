class Solution {
public:
    void clear(queue<pair<int, int>> &q ) {
        queue<pair<int, int>> empty;
        swap(q, empty);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> u(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && u[i][j] == 0) {
                    int area = 0;
                    clear(q);
                    q.push({i, j});
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int r = p.first, c = p.second;
                        if (u[r][c] > 0) continue;
                        u[r][c] = 1;
                        area++;
                        if (r - 1 >= 0 && grid[r - 1][c] > 0 && u[r - 1][c] == 0) {
                            q.push({r - 1, c});
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] > 0 && u[r][c - 1] == 0) {
                            q.push({r, c - 1});
                        }
                        if (r + 1 < n && grid[r + 1][c] > 0 && u[r + 1][c] == 0) {
                            q.push({r + 1, c});
                        }
                        if (c + 1 < m && grid[r][c + 1] > 0 && u[r][c + 1] == 0) {
                            q.push({r, c + 1});
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
