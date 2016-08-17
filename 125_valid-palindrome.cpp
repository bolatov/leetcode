class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (char ch : s) {
            if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9')) {
                t += ch;
            } else if ('A' <= ch && ch <= 'Z') {
                t += (char) (ch + ('a' - 'A'));
            }
        }
        for (int i = 0, j = t.size() - 1; i < j; i++, j--) {
            if (t[i] != t[j]) {
                return 0;
            }
        }
        return 1;
    }
};
