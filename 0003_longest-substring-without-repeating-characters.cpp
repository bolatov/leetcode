class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        unordered_set<char> u;
        int be = 0, en = 0;
        int cnt = 0;
        while (en < s.size()) {
            if (u.count(s[en])) {
                while (s[be] != s[en]) {
                    u.erase(s[be++]);
                }
                while (be < en && s[be] == s[en]) {
                    u.erase(s[be++]);
                }
            }
            
            cnt = max(cnt, en - be + 1);
            u.insert(s[en]);
            en++;
        }
        return cnt;
    }
};
