class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;
        for (string w : words) {
            bool found = true;
            size_t pos = 0;
            for (char ch : w) {
                size_t idx = pos == 0 ? S.find(ch) : S.find(ch, pos + 1);
                if (idx == string::npos) {
                    found = false;
                    break;
                }
                pos = idx;
            }
            if (found)
                ans++;
        }
        return ans;
    }
};
