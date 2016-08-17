class Solution {
public:
    string reverseVowels(string s) {
        string t = "aeiouAEIOU";
        for (int i = 0, j = s.size() - 1; i < j;) {
            for (; t.find(s[i]) == string::npos && i < s.size(); i++) ;
            for (; t.find(s[j]) == string::npos && j >= 0; j--) ;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};
