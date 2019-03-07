class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        set<int> u, v;
        for (int i = 0; i < b.size(); i++) {
            u.clear();
            v.clear();
            for (int j = 0; j < b[i].size(); j++) {
                
                // check row
                if (b[i][j] != '.') {
                    int ch = b[i][j] - '0';
                    if (u.find(ch) != u.end()) {
                        printf("i=%d, j=%d ch=%c ~ %d\n", i+1, j+1, b[i][j], b[i][j]-'0');
                        return 0;
                    }
                    u.insert(ch);
                }
                
                // check column
                if (b[j][i] != '.') {
                    int ch = b[j][i] - '0';
                    if (v.find(ch) != v.end()) {
                        printf("j=%d, i=%d ch=%c ~ %d\n", j+1, i+1, b[j][i], b[j][i]-'0');
                        return 0;
                    }
                    v.insert(ch);
                }
            }
        }
        
        // check 9 sub-boxes
        vector<pair<int,int>> vpii = {
            {0, 0}, {0, 3}, {0, 6},
            {3, 0}, {3, 3}, {3, 6},
            {6, 0}, {6, 3}, {6, 6},
        };
        for (auto p : vpii) {
            u.clear();
            for (int i = p.first; i < p.first + 3; i++) {
                for (int j = p.second; j < p.second + 3; j++) {
                    if (b[i][j] != '.') {
                        int ch = b[i][j] - '0';
                        if (u.find(ch) != u.end()) return 0;
                        u.insert(ch);
                    }
                }
            }
        }
        return 1;
    }
};
