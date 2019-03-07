class Solution {
public:
    int findNthDigit(int n) {
        // 1. [1, 9]        --> [1, 9]
        // 2. [10, 99]      --> [10, 189]
        // 3. [100, 999]    --> [190, 2889]
        // 4. [1000], 9999] --> [2890, 38889]
        vector<int> vi = {0};
        long mx = INT_MAX;
        long x = 0, t = 1;
        for (long i = 1; ; i++) {
            x += 9 * t * i;
            t *= 10;
            vi.push_back(min(x, mx));
            if (x >= mx) break;
        }
        
        int b = 0;
        for (int i = 0; i < vi.size(); i++) {
            if (n > vi[i]) b = i;
        }
        n = n - (vi[b] + 1);
        
        int num = (int)pow(10, b) + n / (b + 1);
        return (int)(to_string(num)[n % (b + 1)] - '0');
    }
};
