class Solution {
  private:
    string sortChars(string s) {
        vector<char> v;
        for (char c : s)
            v.push_back(c);
        sort(v.begin(), v.end());
        string t = "";
        for (char c : v)
            t += c;
        return t;
    }

  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> vvs;
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            auto t = sortChars(s);
            if (m.find(t) != m.end()) {
                m[t].push_back(s);
            } else {
                vector<string> vs = {s};
                m[t] = vs;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            auto vs = it->second;
            sort(vs.begin(), vs.end());
            vvs.push_back(vs);
        }
        return vvs;
    }
};