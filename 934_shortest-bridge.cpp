class Solution {
private:
    int rows;
    int cols;
    vector<vector<bool>> u;
    queue<pair<int, int>> q;
    bool is(int i, int j) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }
    void dfs(vector<vector<int>>& A, int i, int j) {
        u[i][j] = true;
        q.push({i, j});
        if (is(i-1, j) && !u[i-1][j] && A[i-1][j] == 1) {
            u[i-1][j] = true;
            dfs(A, i-1, j);
        }
        if (is(i+1, j) && !u[i+1][j] && A[i+1][j] == 1) {
            u[i+1][j] = true;
            dfs(A, i+1, j);
        }
        if (is(i, j-1) && !u[i][j-1] && A[i][j-1] == 1) {
            u[i][j-1] = true;
            dfs(A, i, j-1);
        }
        if (is(i, j+1) && !u[i][j+1] && A[i][j+1] == 1) {
            u[i][j+1] = true;
            dfs(A, i, j+1);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        rows = A.size();
        cols = A[0].size();
        u = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (A[i][j] == 1) {
                    // Mark the cells that belong to the first island
                    dfs(A, i, j);
                    i = rows;
                    break;
                }
            }
        }
        // printf("\n");
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            // printf("level %d\n", ans);
            while (size--) {
                auto pos = q.front();
                q.pop();
                int i = pos.first;
                int j = pos.second;
                // printf("  visit %d %d\n", i, j);
                if (is(i+1,j) && !u[i+1][j]) {
                    u[i+1][j] = true;
                    if (A[i+1][j] == 1) return ans;
                    q.push({i+1, j});
                    // printf("    add %d %d\n", i+1, j);
                }
                if (is(i-1,j) && !u[i-1][j]) {
                    u[i-1][j] = true;
                    if (A[i-1][j] == 1) return ans;
                    q.push({i-1, j});
                    // printf("    add %d %d\n", i-1, j);
                }
                if (is(i,j+1) && !u[i][j+1]) {
                    u[i][j+1] = true;
                    if (A[i][j+1] == 1) return ans;
                    q.push({i, j+1});
                    // printf("    add %d %d\n", i, j+1);
                }
                if (is(i,j-1) && !u[i][j-1]) {
                    u[i][j-1] = true;
                    if (A[i][j-1] == 1) return ans;
                    q.push({i, j-1});
                    // printf("    add %d %d\n", i, j-1);
                }
            }
            ans++;
        }
        
        return -1;
    }
};
