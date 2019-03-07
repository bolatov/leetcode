class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int cnt2 = 0;
        for (int i = 0; i < n;) {
            int cnt1 = 0;
            int j = i;
            for (; j < n && s[j] == s[i]; j++) {
                cnt1++;
            }
            ans += min(cnt1, cnt2);
            i = j;
            cnt2 = cnt1;
        }
        return ans;
    }
};

