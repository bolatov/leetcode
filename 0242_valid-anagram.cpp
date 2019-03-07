class Solution {
  public:
    bool isAnagram(string s, string t) {
        int n = 1024;
        vector<int> vs(n, 0), vt(n, 0);
        for (int i = 0; i < s.size(); i++)
            vs[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            vt[t[i]]++;

        for (int i = 0; i < n; i++)
            if (vs[i] != vt[i])
                return 0;
        return 1;
    }
};