class Solution {
public:
    bool isHappy(int n) {
        set<int> si;
        int m;
        while (1) {
            if (si.find(n) != si.end()) break;
            si.insert(n);
            m = 0;
            while (n) {
                m += pow(n % 10, 2);
                n /= 10;
            }
            if (m == 1) return 1;
            n = m;
        }
        return 0;
    }
};