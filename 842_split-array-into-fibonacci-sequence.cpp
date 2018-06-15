class Solution {
public:
    const size_t MAX_LEN = 10;
    const string MAX_INT = to_string(INT_MAX);
    bool check(string s, vector<int>& v) {
        if (s.empty()) return true;
        int sum = v[v.size() - 1] + v[v.size() - 2];
        string t = to_string(sum);
        if (t != s.substr(0, t.size())) {
            return false;
        }
        v.push_back(sum);
        return check(s.substr(t.size()), v);
    }
    vector<int> splitIntoFibonacci(string s) {
        for (int i = 1; i <= min(s.size(), MAX_LEN); i++) {
            string fir = s.substr(0, i);
            if (fir.size() == MAX_INT.size() && fir > MAX_INT) break;
            if (i > 1 && fir[0] == '0') break;
            for (int j = 1; j <= min(s.size() - i, MAX_LEN); j++) {
                vector<int> v;
                v.push_back(stoi(fir));
                string sec = s.substr(i, j);
                if (sec.size() == MAX_INT.size() && sec > MAX_INT) break;
                if (j > 1 && sec[0] == '0') break;
                v.push_back(stoi(sec));
                string suffix = s.substr(i + j);
                if (check(suffix, v) && v.size() >= 3) {
                    return v;
                }
            }
        }
        return {};
    }
};
