class Solution {
public:
    string addStrings(string s, string t) {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int i, q = 0;
        string u = "";
        for (i = 0; i < s.size() && i < t.size(); i++) {
            int k = (s[i] - '0') + (t[i] - '0') + q;
            u += to_string(k % 10);
            q = k / 10;
        }
        
        string v = (s.size() > t.size()) ? s : t;
        for (; i < v.size(); i++) {
            int k = (v[i] - '0') + q;
            u += to_string(k % 10);
            q = k / 10;
        }
        
        if (q) {
            u += to_string(q);
        }
        
        reverse(u.begin(), u.end());
        return u;
    }
};
