class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        
        unsigned int n;
        if (num < 0) {
            num *= -1;
            num--;
            n = ((INT_MAX << 1) | 1) - num;
        } else {
            n = num;
        }
        string s = "";
        while (n) {
            int q = n % 16;
            n /= 16;
            switch (q) {
                case 10:
                    s += 'a';
                    break;
                case 11:
                    s += 'b';
                    break;
                case 12:
                    s += 'c';
                    break;
                case 13:
                    s += 'd';
                    break;
                case 14:
                    s += 'e';
                    break;
                case 15:
                    s += 'f';
                    break;
                default:
                    s += to_string(q);
                    break;
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
