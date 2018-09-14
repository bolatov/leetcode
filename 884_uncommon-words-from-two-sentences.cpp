class Solution {
private:
    vector<string> getWords(string str) {
        vector<string> vs;
        string s = "";
        for (char ch : str) {
            if (ch == ' ') {
                if (!s.empty()) {
                    vs.push_back(s);
                }
                s = "";
            } else {
                s += ch;
            }
        }
        if (!s.empty()) vs.push_back(s);
        return vs;
    }
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> mp;
        for (string s : getWords(A)) {
            if (!mp.count(s)) mp[s] = 0;
            mp[s]++;
        }
        for (string s : getWords(B)) {
            if (!mp.count(s)) mp[s] = 0;
            mp[s]++;
        }
        
        vector<string> vs;
        for (auto kv : mp) {
            if (kv.second == 1) vs.push_back(kv.first);
        }
        return vs;
    }
};
