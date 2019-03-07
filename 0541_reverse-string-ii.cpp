class Solution {
public:
    string reverseStr(string s, int k) {
        if (k <= 0) return s;
        int n = s.size();
        for (int i = 0; i < n; i += k * 2) {
            int begin = i, end = min(i + k, n) - 1;
            while (begin < end) {
                swap(s[begin], s[end]);
                begin++;
                end--;
            }
        }
        
        return s;
    }
};
