class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        for (int col = 0; col < m[0].size(); col++) {
            for (int i = 1, j = col + 1; i < m.size() && j< m[0].size(); i++, j++) {
                if (m[i][j] != m[i - 1][j - 1]) return false;
            }
        }
        for (int row = 1; row < m.size(); row++) {
            for (int i = row + 1, j = 1; i < m.size() && j < m[0].size(); i++, j++) {
                if (m[i][j] != m[i - 1][j - 1]) return false;
            }
        }
        return true;
    }
};