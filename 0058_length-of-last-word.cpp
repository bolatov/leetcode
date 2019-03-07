class Solution {
  public:
    int lengthOfLastWord(string s) {
        // ltrim
        while (!s.empty() && s[0] == ' ') {
            s.erase(s.begin());
        }

        // rtrim
        while (!s.empty() && s[s.size() - 1] == ' ') {
            s.erase(s.end() - 1);
        }

        // search for a first space starting from the right
        if (s.rfind(" ") != string::npos) {
            return s.substr(s.rfind(" ") + 1).size();
        }

        return s.size();
    }
};