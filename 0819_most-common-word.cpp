class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> mp;
        string s = "";
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        for (char ch : paragraph) {
            if ('a' <= ch && ch <= 'z') {
                s += ch;
            } else {
                if (!s.empty() && find(banned.begin(), banned.end(), s) == banned.end()) {
                    if (mp.find(s) == mp.end()) {
                        mp[s] = 0;
                    }
                    mp[s] += 1;
                }
                s = "";
            }
        }
        if (!s.empty() && find(banned.begin(), banned.end(), s) == banned.end()) {
            if (mp.find(s) == mp.end()) {
                mp[s] = 0;
            }
            mp[s] += 1;
        }
        
        int cnt = 0;
        string w;
        for (auto kv : mp) {
            if (kv.second > cnt) {
                cnt = kv.second;
                w = kv.first;
            }
        }
        return w;
    }
};
