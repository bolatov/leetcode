class Solution {
private:
    bool check(const string& s, const string& t) {
        if (t.size() > s.size()) return false;
        
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) j++;
            i++;
        }
        return j == t.size();
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        auto comp = [](const string& s1, const string& s2){
            return s1.size() == s2.size() ? s1 < s2 : s1.size() > s2.size();
        };
        sort(d.begin(), d.end(), comp);
        for (string k : d) {
            if (check(s, k)) {
                return k;
            }
        }
        return "";
    }
};
