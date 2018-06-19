class Solution {
public:
    void reverseWords(string &s) {
        // reverse the whole string
        int be = 0, en = s.size() - 1;
        while (be <= en) { swap(s[be++], s[en--]); }
        
        // reverse each word
        for (int i = 0; i < s.size();) {
            for (be = i; be < s.size() && s[be] == ' '; be++);
            for (en = be; en < s.size() && s[en] != ' '; en++);
            i = en--;
            while (be <= en) {swap(s[be++], s[en--]);}
        }
        
        // replace multiple spaces with single ones
        for (int i = 0; i < s.size(); i += en - be + 1) {
            for (be = i; be < s.size() && s[be] == ' '; be++);
            if (be == i) break;
            for (en = be; en < s.size() && s[en] != ' '; en++) {
                s[en - (be - i)] = s[en];
                s[en] = ' ';
            }
        }
        
        // remove trailing spaces
        for (en = s.size() - 1; en >= 0 && s[en] == ' '; en--) {
            s[en] = NULL;
        }
    }
};
