class Solution {
  private:
    vector<string> split(string s) {
        vector<string> v;
        string buf = "";
        for (char c : s) {
            if (c != ' ') {
                buf += c;
            } else {
                v.push_back(buf);
                buf = "";
            }
        }
        v.push_back(buf);
        return v;
    }

  public:
    bool wordPattern(string pattern, string str) {
        auto vs = split(str);
        if (pattern.size() != vs.size())
            return false;

        map<char, string> mcs;
        map<string, char> msc;
        for (int i = 0; i < vs.size(); i++) {
            char c = pattern[i];
            if (mcs.find(c) != mcs.end() && mcs[c] != vs[i])
                return false;
            mcs[c] = vs[i];
            if (msc.find(vs[i]) != msc.end() && msc[vs[i]] != c)
                return false;
            msc[vs[i]] = c;
        }
        return true;
    }
};