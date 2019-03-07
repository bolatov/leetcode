class Solution {
public:
    int bulbSwitch(int n) {
        // count perfect squares <= n
        int cnt = 0;
        for (int i = 1; ; i++) {
            if (i * i > n) break;
            cnt++;
        }
        return cnt;
    }
};
