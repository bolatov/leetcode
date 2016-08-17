class Solution {
  public:
    int titleToNumber(string s) {
        int r = 0;
        int q = 1;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            int k = s[i] - 'A' + 1;
            r += k * q;
            q *= 26;
        }
        return r;
    }
};