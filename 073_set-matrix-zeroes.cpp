class Solution {
  public:
    // Could you devise a constant space solution?
    void setZeroes(vector<vector<int>> &m) {
        if (m.empty())
            return;
        int N = m.size(), M = m[0].size();
        vector<bool> rows(N, 0), cols(M, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (m[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (rows[i] || cols[j])
                    m[i][j] = 0;
            }
        }
    }
};