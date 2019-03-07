class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        vector<vector<int>> vvi(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                double cnt = 1.0;
                double sum = (double) M[i][j];
                if (i - 1 >= 0) {
                    
                    if (j - 1 >= 0) {
                        cnt += 1;
                        sum += M[i - 1][j - 1];
                    }
                    
                    cnt += 1;
                    sum += M[i - 1][j];
                    
                    if (j + 1 < m) {
                        cnt += 1;
                        sum += M[i - 1][j + 1];
                    }
                }
                
                if (j - 1 >= 0) {
                    cnt += 1;
                    sum += M[i][j - 1];
                }
                
                if (j + 1 < m) {
                    cnt += 1;
                    sum += M[i][j + 1];
                }
                
                if (i + 1 < n) {
                    if (j - 1 >= 0) {
                        cnt += 1;
                        sum += M[i + 1][j - 1];
                    }
                    
                    cnt += 1;
                    sum += M[i + 1][j];
                    
                    if (j + 1 < m) {
                        cnt += 1;
                        sum += M[i + 1][j + 1];
                    }
                }
                vvi[i][j] = sum / cnt;
            }
        }
        return vvi;
    }
};
