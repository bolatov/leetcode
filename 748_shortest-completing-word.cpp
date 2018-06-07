class Solution {
public:
    static const int ALPH_SIZE = 256;
    vector<int> f(string s) {
        vector<int> v(ALPH_SIZE, 0);
        for (char ch : s) {
            if ('a' <= ch && ch <= 'z') {
                v[(int) ch]++;
            }
        }
        return v;
    }
    bool ok(string lp, string s, vector<int>& vl) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        vector<int> vs = f(s);
        // pv(vs);
        for (int i = 0; i < ALPH_SIZE; i++) {
            if (vs[i] < vl[i]) {
                return false;
            }
        }
        return true;
    }
    // void pv(vector<int>& v) {
    //     for (int i = 0; i < v.size(); i++) {
    //         if (v[i] > 0)
    //         printf("%c=%d ", (char) i, v[i]);
    //     }
    //     printf("\n");
    // }
    string shortestCompletingWord(string lp, vector<string>& vs) {
        int len = INT_MAX;
        string t;
        transform(lp.begin(), lp.end(), lp.begin(), ::tolower);
        auto vl = f(lp);
        // pv(vl);
        for (string s : vs) {
            if ((INT_MAX == len && ok(lp, s, vl)) || (len < INT_MAX && s.size() < len && ok(lp, s, vl))) {
                len = s.size();
                t = s;
                // printf("t=%s len=%d\n", t.c_str(), len);
            }
        }
        
        return t;
    }
};
