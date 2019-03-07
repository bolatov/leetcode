class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        char chr = ' ';
        for (char ch : s) {
            if (ch != ' ') {
                chr = ch;
            } else if (chr != ' ') {
                cnt++;
                chr = ' ';
            }
        }
        cnt += chr != ' ';
        return cnt;
    }
};
