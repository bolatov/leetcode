class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t sz = strs.size();
        if (sz == 0) return "";
        else if (sz == 1) return strs[0];
        
        sort(strs.begin(), strs.end());
        int len = 0;
        string f = strs[0];
        string l = strs[sz - 1];
        for (int i = 0; i < min(f.size(), l.size()); i++) {
            if (f[i] != l[i]) break;
            len = i + 1;
        }
        return f.substr(0, len);
    }
};
