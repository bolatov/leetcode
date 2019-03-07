class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int minLen = min(a.size(), b.size());
        int i;
        int q = 0;
        string c = "";
        for (i = 0; i < minLen; i++) {
            int ai = (int) (a[i] - '0');
            int bi = (int) (b[i] - '0');
            int ci = ai + bi + q;
            c += to_string(ci % 2);
            q = ci / 2;
        }
        string r = a.size() > b.size() ? a : b;
        for (; i < r.size(); i++) {
            int ai = (int) (r[i] - '0');
            int ci = ai + q;
            c += to_string(ci % 2);
            q = ci / 2;
        }
        if (q) {
            c += to_string(q);
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
