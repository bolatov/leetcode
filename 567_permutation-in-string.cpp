class Solution {
private:
    vector<int> getFrequencies(string s) {
        vector<int> v(26, 0);
        for (char ch : s) {
            v[ch - 'a']++;
        }
        return v;
    }
    
    bool compareFrequencies(vector<int>& u, vector<int>& v) {
        for (int i = 0; i < u.size(); i++) {
            if (u[i] != v[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        int len = s1.size();
        vector<int> v = getFrequencies(s1);
        
        string sub = s2.substr(0, len);
        vector<int> u = getFrequencies(sub);
        
        if (compareFrequencies(v, u)) {
            return true;
        }
        
        for (int i = 1; i <= s2.size() - len; i++) {
            u[s2[i - 1] - 'a']--;
            u[s2[i - 1 + len] - 'a']++;
            if (compareFrequencies(v, u)) {
                return true;
            }
        }
        return false;
    }
};
