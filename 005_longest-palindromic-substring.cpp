class Solution {
private:
    string expand(string s, int lo, int hi) {
        int len = s.size();
        while (lo >= 0 && hi < len && s[lo] == s[hi]) {
            lo--;
            hi++;
        }
        return s.substr(lo + 1, hi - lo - 1);
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        string cur;
        for (int i = 0; i < s.size(); i++) {
            cur = expand(s, i, i);
            if (cur.size() > ans.size()) {
                ans = cur;
            }
            
            cur = expand(s, i, i + 1);
            if (cur.size() > ans.size()) {
                ans = cur;
            }
        }
        
        return ans;
    }
};
