class Solution {
public:
    int romanToInt(string s) {
        vector<int> v(s.size());
        for (char ch : s) {
            int i;
            switch (ch) {
                case 'I':
                    i = 1;
                    break;
                case 'V':
                    i = 5;
                    break;
                case 'X':
                    i = 10;
                    break;
                case 'L':
                    i = 50;
                    break;
                case 'C':
                    i = 100;
                    break;
                case 'D':
                    i = 500;
                    break;
                case 'M':
                    i = 1000;
                    break;
            }
            v.push_back(i);
        }
        int r = 0, c = v[0];
        for (int i = 1; i < (int)v.size(); ++i) {
            if (v[i] <= v[i - 1]) {
                c += v[i];
            } else if (v[i] > v[i - 1]) {
                r += v[i] - c;
                c = 0;
            }
        }
        if (c) {
            r += c;
        };
        return r;
    }
};