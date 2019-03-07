class Solution {
private:
    
    void search(vector<vector<string>>& vvs, vector<bool>& column, 
                vector<bool>& diag1, vector<bool>& diag2, const int N, vector<string> vs) {
        int y = vs.size();
        if (y == N) {
            // pr(vs);
            vvs.push_back(vs);
            return;
        }
        
        for (int x = 0; x < N; x++) {
            if (column[x] || diag1[x + y] || diag2[x - y + N - 1]) {
                continue;
            }
            column[x] = diag1[x + y] = diag2[x - y + N - 1] = 1;
            string s(N, '.');
            s[x] = 'Q';
            vs.push_back(s);
            search(vvs, column, diag1, diag2, N, vs);
            column[x] = diag1[x + y] = diag2[x - y + N - 1] = 0;
            vs.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vvs;
        vector<bool> column(n, false), diag1(n, false), diag2(n, false);
        search(vvs, column, diag1, diag2, n, {});
        return vvs;
    }
};
