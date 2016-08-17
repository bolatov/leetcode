class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        for (int i = 0, j = s.size()-1; i < j; i++, j--)
            if (s[i] != s[j]) return 0;
        return 1;
    }
};
