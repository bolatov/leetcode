class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        unordered_map<int, unordered_set<string>> mp;
        int maxLen = 0;
        for (string w : words) {
            int len = w.size();
            if (mp.find(len) == mp.end()) {
                unordered_set<string> st;
                mp[len] = st;
            }
            mp[len].insert(w);
            maxLen = max(maxLen, len);
        }
        
        auto st = mp[1];
        for (int len = 2; len <= maxLen; len++) {
            unordered_set<string> sts;
            for (string w : mp[len]) {
                string sub = w.substr(0, len - 1);
                if (st.find(sub) != st.end()) {
                    sts.insert(w);
                }
            }
            if (sts.empty()) {
                break;
            }
            st = sts;
        }
        
        for (string w : st) {
            if (ans.empty() || w.size() > ans.size() || (ans.size() == w.size() && w < ans)) {
                ans = w;
            }
        }
        
        return ans;
    }
};
