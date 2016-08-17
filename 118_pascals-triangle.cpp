class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vvi(numRows);
        if (numRows <= 0) return vvi;
        for (int i = 0; i < numRows; i++) {
            vector<int> v(i+1, 1);
            if (i > 1) {
                for (int j = 1; j < vvi[i-1].size(); j++) {
                    v[j] = vvi[i-1][j] + vvi[i-1][j-1];
                }
            }
            vvi[i] = v;
        }
        return vvi;
    }
};
