class Solution {
private:
    int bits(int n) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                cnt++;
            }
        }
        return cnt;
    }
public:
    vector<string> readBinaryWatch(int n) {
        vector<string> v;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (bits(i) + bits(j) == n) {
                    v.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
                }
            }
        }
        return v;
    }
};
