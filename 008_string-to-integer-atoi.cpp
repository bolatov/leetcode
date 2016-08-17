class Solution {
public:
    int myAtoi(string str) {
        long long n = 0;
        bool negative = 0, started = 0;
        for (char ch : str) {
            if (!started) {
                if ('0' <= ch && ch <= '9') {
                    started = 1;
                    n = ch - '0';
                } else if (ch == '+') {
                    started = 1;
                } else if (ch == '-') {
                    started = 1;
                    negative = 1;
                } else if (ch != ' ' && ch != '\t') {
                    break;
                }
            } else if (started && !('0' <= ch && ch <= '9')) {
                break;
            } else {
                n = n * 10 + (ch - '0');
                
                if (n > INT_MAX) {
                    return negative ? INT_MIN : INT_MAX;
                }
            }
        }
        
        return negative ? -n : n;
    }
};
