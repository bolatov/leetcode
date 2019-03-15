class Solution {
public:
    int minAddToMakeValid(string S) {
        int openBraces = 0;
        int missingBraces = 0;
        for (char ch : S) {
            if (ch == '(') {
                openBraces++;
            } else {
                if (openBraces > 0) {
                    openBraces--;
                } else {
                    missingBraces++;
                }
            }
        }
        return openBraces + missingBraces;
    }
};
