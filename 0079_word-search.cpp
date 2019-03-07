class Solution {
private:
    bool isBetween(int i, int size) {
        return 0 <= i && i < size;
    }

    bool dfs(vector<vector<char>>& b, pair<int, int> pos, string word, set<pair<int, int>> u) {
        if (word.empty()) {
            return true;
        }
        
        int n = b.size();
        int m = b.empty() ? 0 : b[0].size();
        
        
        int row = pos.first;
        int col = pos.second;
        
        if (!isBetween(row, n) || !isBetween(col, m) || u.find(pos) != u.end() || b[row][col] != word[0]) {
            return false;
        }
        
        // mark as visited
        u.insert(pos);
        
        return 
        
            // east
            dfs(b, {row, col + 1}, word.substr(1), u) ||
        
            // south
            dfs(b, {row + 1, col}, word.substr(1), u) ||
        
            // west
            dfs(b, {row, col - 1}, word.substr(1), u) ||
        
            // north
            dfs(b, {row - 1, col}, word.substr(1), u);
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board.empty() ? 0 : board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                if (board[i][j] != word[0]) {
                    continue;
                }
                
                if (dfs(board, {i, j}, word, set<pair<int, int>>())) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
