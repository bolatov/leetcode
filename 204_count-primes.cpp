class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n, 1);
        int primes = 0;
        for (int i = 2; i*i < n; i++) {
            if (v[i]) {
                for (int j = i * i; j < n; j += i) {
                    v[j] = 0;
                }
            }
        }
        for (int i = 2; i < n; i++)
            if (v[i]) primes++;
        return primes;
    }
};
