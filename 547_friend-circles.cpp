
class Solution {
public:
    void dfs(vector<vector<int>>& M, int i, vector<bool>& u) {
        u[i] = true;
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] && !u[j]) dfs(M, j, u);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<bool> u(n, false);
        int circles = 0;
        for (int i = 0; i < n; i++) {
            if (!u[i]) {
                dfs(M, i, u);
                circles++;
            }
        }
        return circles;
    }
};
