class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> vvi;
        int be = 0;
        int cnt = 1;
        char ch = S[0];
        for (int i = 1; i < S.size(); i++) {
            if (S[i] != ch) {
                if (i - be >= 3) {
                    vvi.push_back({be, i - 1});
                }
                be = i;
                ch = S[i];
            }
        }
        if (S.size() - be >= 3) vvi.push_back({be, S.size() - 1});
        return vvi;
    }
};
