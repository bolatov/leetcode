class Solution {
public:
    bool detectCapitalUse(string word) {
        // all uppercase
        bool isUpper = true;
        for (char ch : word) if ('a' <= ch && ch <= 'z') isUpper = false;
        
        // all lowercase
        bool isLower = true;
        for (char ch : word) if ('A' <= ch && ch <= 'Z') isLower = false;
        
        // camelcase
        bool isCamel = 'A' <= word[0] && word[0] <= 'Z';
        for (int i = 1; i < word.size(); i++) if ('A' <= word[i] && word[i] <= 'Z') isCamel = false;
        return isUpper || isLower || isCamel;
    }
};
