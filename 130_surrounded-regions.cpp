class Solution {
private:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& u, int i, int j, const int key) {
        u[i][j] = key;
        
        bool res = !(i == 0 || j == 0 || i + 1 == board.size() || j + 1 == board[0].size());
        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !u[i - 1][j]) res &= dfs(board, u, i - 1, j, key);
        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !u[i][j - 1]) res &= dfs(board, u, i, j - 1, key);
        if (i + 1 < board.size() && board[i + 1][j] == 'O' && !u[i + 1][j]) res &= dfs(board, u, i + 1, j, key);
        if (j + 1 < board[0].size() && board[i][j + 1] == 'O' && !u[i][j + 1]) res &= dfs(board, u, i, j + 1, key);
        return res;
    }
public:
    /**
     * Traverse board cells with letter 'O' by a BFS. 
     * Mark each visited region with a special key (`key = i * n + j + 1`).
     * If any region touches the border, then it is not surrounded by 'X'.
     *
     * NOTE: Marking the regions serves for UNION-FIND operations.
     */
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = n > 0 ? board[0].size() : 0;
        vector<vector<int>> u(n, vector<int>(m, 0));
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !u[i][j]) {
                    int key = i * n + j + 1;
                    mp[key] = dfs(board, u, i, j, key);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int key = u[i][j];
                if (mp.count(key) && mp[key] == true) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
