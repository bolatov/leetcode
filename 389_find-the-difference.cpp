class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> vs(26, 0), vt(26, 0);
        for (char c : s) vs[c-'a']++;
        for (char c : t) vt[c-'a']++;
        for (int i = 0; i < vt.size(); i++)
            if (vt[i] > vs[i])
                return (char) (i + 'a');
        return '0';
    }
};
