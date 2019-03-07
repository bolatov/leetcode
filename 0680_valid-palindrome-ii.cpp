class Solution {
public:
    bool check(string s) {
        int be = 0, en = s.size() - 1;
        while (be < en) if (s[be++] != s[en--]) return false;
        return true;
    }
    bool validPalindrome(string s) {
        int be = 0, en = s.size() - 1;
        while (be < en) {
            if (s[be] != s[en]) {
                break;
            }
            be++;
            en--;
        }
        if (be >= en) return true;
        if (check(s.substr(0, be) + s.substr(be + 1)) || 
            check(s.substr(0, en) + s.substr(en + 1))) {
            return true;
        }
        return false;
    }
};
