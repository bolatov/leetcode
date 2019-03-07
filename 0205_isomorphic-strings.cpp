class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return 0;

        // calculate mappings (char->char)
        vector<char> v(256, -1), u(256, -1);
        for (int i = 0; i < (int)s.size(); i++) {
            v[s[i]] = t[i];
            u[s[i]] = t[i];
        }

        // check if two different characters map to the same character
        sort(u.begin(), u.end());
        for (int i = 1; i < u.size(); i++) {
            if (u[i] != -1 && u[i] == u[i - 1])
                return 0;
        }

        // map characters from string 's' and check whether they (characters)
        // map to characters in string 't'
        for (int i = 0; i < (int)s.size(); i++) {
            if (v[s[i]] != t[i])
                return 0;
        }
        return 1;
    }
};