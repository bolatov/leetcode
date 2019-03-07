class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string k = s;
        for (int i = 0; i + 1 < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] < s[j]) {
                    swap(s[i], s[j]);
                    k = max(s, k);
                    swap(s[i], s[j]);
                }
            }
        }
        return stoi(k);
    }
};
