class Solution {
private:
    int expand(string s, int lo, int hi) {
        int len = s.size();
        int cnt = 0;
        while(lo >= 0 && hi < len && s[lo] == s[hi]) {
            lo--;
            hi++;
            cnt++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += expand(s, i, i);
            cnt += expand(s, i, i + 1);
        }
        return cnt;
    }
};
