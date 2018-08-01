class Solution {
public:
    bool compare(int i, int k) {
        string s = to_string(i);
        string t = to_string(k);
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    bool reorderedPowerOf2(int N) {
        for (int i = 0; i < 32; i++) {
            if (compare(N, (1 << i))) return true;
        }
        return false;
    }
};
