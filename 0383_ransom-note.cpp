class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vr(26, 0), vm(26, 0);
        for (char c : ransomNote) vr[c - 'a']++;
        for (char c : magazine) vm[c - 'a']++;
        for (int i = 0; i < vr.size(); i++)
            if (vr[i] > vm[i])
                return 0;
        return 1;
    }
};
