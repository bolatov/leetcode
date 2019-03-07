class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) return s;
        vector<vector<char>> vs(numRows, vector<char>());
        for (int i = 0, k = 0; k < s.size();) {
            if (i == 0) {
                for (; i < numRows && k < s.size(); i++)
                    vs[i].push_back(s[k++]);
                i--;
            } else {
                vs[i].push_back(s[k++]);
            }
            i--;
        }
        
        string t = "";
        for (auto row : vs) {
            for (auto ch : row) {
                t += ch;
            }
        }
        return t;
    }
};
