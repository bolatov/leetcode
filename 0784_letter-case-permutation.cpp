class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> vs;
        int sz = S.size();
        queue<pair<string, int>> q;
        q.push({S, 0});
        int diff = abs('a' - 'A');
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            string s = p.first;
            int lev = p.second;
            
            if (lev == sz) {
                vs.push_back(s);
            } else if ('0' <= s[lev] && s[lev] <= '9') {
                q.push({s, lev + 1});
            } else {
                bool isLower = 'a' <= s[lev] && s[lev] <= 'z';
                string p = s;
                
                if (isLower) {
                    p[lev] = (char) (s[lev] - diff);
                } else {
                    p[lev] = (char) (s[lev] + diff);
                }
                q.push({s, lev + 1});
                q.push({p, lev + 1});
            }
        }
        return vs;
    }
};