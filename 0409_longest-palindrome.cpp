class Solution {
public:
    int longestPalindrome(string s) {
        const int size = 256;
        vector<int> v(size, 0);
        for (char ch : s) {
            v[ch]++;
        }
        bool hasOdd = 0;
        int len = 0;
        for (int i : v) {
            if (i == 0) {
                continue;
            } else if (i % 2) {
                hasOdd = 1;
            }
            len += i - (i % 2);
        }
        len += (hasOdd ? 1 : 0);
        return len;
    }
};
