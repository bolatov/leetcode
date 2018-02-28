class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> vi;
        for (int i = left; i <= right; i++) {
            bool is = 1;
            int num = i;
            while (num > 0 && is) {
                int digit = num % 10;
                if (digit == 0 || i % digit != 0) {
                    is = 0;
                }
                num /= 10;
            }
            if (is) {
                vi.push_back(i);
            }
        }
        return vi;
    }
};