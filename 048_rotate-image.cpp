class Solution {
private:
    void pm(vector<pair<int, int>> vp, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                string ok = ".";
                for (int k = 0; k < vp.size(); k++) {
                    if (vp[k].first == i && vp[k].second == j) {
                        ok = to_string(k);
                    }
                }
                printf("%s ", ok.c_str());
            }
            printf("\n");
        }
        printf("-------------------\n");
    }
public:
    void rotate(vector<vector<int>>& m) {
        int sign = 1;
        int n = m.size();
        // There are at most n/2 rings (levels) 
        // of the matrix
        for (int level = 0; level < n / 2; level++) {
            // borders
            int start = level;
            int end = n - level - 1;
            for (int row = level, col = level; col < end; col++) {
                int step = col - level;
                int i = row, j = col;
                int i1 = row + step, j1 = end;
                int i2 = end, j2 = end - step;
                int i3 = end - step, j3 = col - step;
                
                vector<pair<int, int>> vp = {
                    {i, j}, {i1, j1}, {i2, j2}, {i3, j3}
                };
                //pm(vp, n);
                
                int t = m[i1][j1];
                m[i1][j1] = m[i][j];
                m[i][j] = t;
                
                t = m[i2][j2];
                m[i2][j2] = m[i][j];
                m[i][j] = t;
                
                t = m[i3][j3];
                m[i3][j3] = m[i][j];
                m[i][j] = t;
            }
        }
    }
};
