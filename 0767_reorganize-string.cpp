class Solution {
public:
    string reorganizeString(string S) {
        vector<int> vi(26, 0);
        for (char ch : S) vi[ch - 'a']++;
        string t = "";
        while (t.size() != S.size()) {
            int idx = -1;
            int cnt = 1;
            for (int i = 0; i < vi.size(); i++) {
                if (vi[i] >= cnt && (t.empty() || t[t.size() - 1] != 'a' + i)) {
                    cnt = vi[i];
                    idx = i;
                }
            }
            if (idx < 0) return "";
            t += 'a' + idx;
            vi[idx]--;
        }
        return t;
    }
};
