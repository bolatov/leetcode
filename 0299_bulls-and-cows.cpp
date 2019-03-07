class Solution {
public:
    string getHint(string s, string g) {
        int b = 0, c = 0;
        vector<bool> u(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == g[i]) {
                b++;
                u[i] = 1;
            }
        }
        vector<int> vi(10, 0), vj(10, 0);
        for (int i = 0; i < s.size(); i++) {
            if (!u[i]) {
                vi[s[i] - '0']++;
                vj[g[i] - '0']++;
            }
        }
        
        for (int i = 0; i < vi.size(); i++)
            c += min(vi[i], vj[i]);
        
        return to_string(b) + "A" + to_string(c) + "B";
    }
};
