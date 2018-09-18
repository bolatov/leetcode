class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> vs;
        for (string w : words) {
            if (w.size() != pattern.size()) continue;
       
            // Find a bijection between letters
            unordered_map<char, char> mwp, mpw;
            for (int i = 0; i < w.size(); i++) {
                mwp[w[i]] = pattern[i];
                mpw[pattern[i]] = w[i];
            }
            
            // Use created bijection to check whether
            // mapping word->pattern && pattern->word give
            // same results.
            string w2 = w;
            string p2 = pattern;
            for (int i = 0; i < w.size(); i++) {
                w2[i] = mpw[pattern[i]];
                p2[i] = mwp[w[i]];
            }
            
            if (w == w2 && pattern == p2) {
                vs.push_back(w);
            }
        }
        return vs;
    }
};
