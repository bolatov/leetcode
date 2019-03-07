class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string s = "";
        bool isNegative = num < 0;
        if (isNegative) num *= -1;
        while (num > 0) {
            s += to_string(num % 7);
            num /= 7;
        }
        
        reverse(s.begin(), s.end());
        if (isNegative) {    
            s = "-" + s;
        }
        return s;
    }
};
