class Solution {
public:
    static const int ALPHABET_SIZE = 26;
    
    vector<int> f(string s) {
        vector<int> v(ALPHABET_SIZE, 0);
        for (char ch : s) {
            v[ch - 'a']++;
        }
        return v;
    }
    bool equals(vector<int>& v, vector<int>& u) {
        for (int i = 0; i < v.size(); i++)
            if (v[i] != u[i]) return false;
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> vi;
        int n = s.size();
        int m = p.size();
        if (m > n) return vi;
        auto vp = f(p);
        auto vs = f(s.substr(0, m));
        if (equals(vp, vs)) vi.push_back(0);
        for (int i = m; i < n; i++) {
            char fir = s[i - m];
            char cur = s[i];
            vs[cur - 'a']++;
            vs[fir - 'a'] = max(0, vs[fir - 'a'] - 1);
            
            if (equals(vs, vp)) vi.push_back(i - m + 1);
        }
        
        return vi;
    }
};
