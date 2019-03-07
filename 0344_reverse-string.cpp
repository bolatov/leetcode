class Solution {
  public:
    string reverseString(string s) {
        int n = (int)s.size();
        for (int i = 0; i < n / 2; i++) {
            char t = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = t;
        }
        return s;
    }
};