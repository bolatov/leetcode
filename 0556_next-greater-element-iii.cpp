class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 0) return -1;
        long x = n;
        string s = to_string(x);
        int pos = s.size() - 2;
        for (; pos >= 0; pos--) {
            if (s[pos] < s[pos + 1]) break;
        }
        if (pos < 0) return -1;
        int k = pos + 1;
        for (int j = k; j < s.size(); j++) {
            if (s[j] > s[pos] && s[j] < s[k]) k = j;
        }
        swap(s[pos], s[k]);
        sort(s.begin() + pos + 1, s.end());
        x = stol(s);
        return x <= INT_MAX ? x : -1;
    }
};
