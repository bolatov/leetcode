class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        string c = string(1, C);
        size_t f = S.find(c);
        size_t s = f;
        vector<int> vi(S.size(), S.size());
        
        for (size_t i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                vi[i] = 0;
                f = i;
                s = S.find(c, f + 1);
                s = (s == string::npos) ? INT_MAX : s;
            } else {
                vi[i] = min(max(i, f) - min(i, f), max(i, s) - min(i, s));                
            }
        }
        return vi;
    }
};