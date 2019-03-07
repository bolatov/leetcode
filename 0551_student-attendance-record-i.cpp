class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        for (char ch : s) if (ch == 'A') a++;
        return !(a > 1 || s.find("LLL") != string::npos);
    }
};
