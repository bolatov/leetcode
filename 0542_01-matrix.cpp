class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mm) {
        int n = mm.size();
        int m = n > 0 ? mm[0].size() : 0;
        int row = -1, col = -1;
        vector<vector<int>> d(n, vector<int>(m, n + m));
        vector<vector<bool>> u(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mm[i][j]) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if (u[i][j]) continue;
            u[i][j] = true;
            int dist = d[i][j] + 1;
            
            // east
            if (j + 1 < m && dist < d[i][j + 1]) {
                d[i][j + 1] = dist;
                q.push({i, j + 1});
            }
            
            // south
            if (i + 1 < n && dist < d[i + 1][j]) {
                d[i + 1][j] = dist;
                q.push({i + 1, j});
            }
            
            // west
            if (j - 1 >= 0 && dist < d[i][j - 1]) {
                d[i][j - 1] = dist;
                q.push({i, j - 1});
            }
            
            // north
            if (i - 1 >= 0 && dist < d[i - 1][j]) {
                d[i - 1][j] = dist;
                q.push({i - 1, j});
            }
        }
        
        return d;
    }
};
