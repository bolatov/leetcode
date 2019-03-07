class Solution {
public:
    string reverseWords(string s) {
        size_t prev = 0;
        for (size_t pos = s.find(' ', prev); pos != string::npos; pos = s.find(' ', prev)) {
            reverse(s.begin() + prev, s.begin() + pos);
            prev = pos + 1;
        }
        reverse(s.begin() + prev, s.end());
        return s;
    }
};
