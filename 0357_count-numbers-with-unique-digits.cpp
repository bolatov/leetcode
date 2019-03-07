class Solution {
private:
    /*
     * fact(n) / fact(n-r)
     */
    int perm(int n, int r) {
        int k = 1;
        for (int i = n - r + 1; i <= n; i++) {
            k *= i;
        }
        return k;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int sum = 0;
        
        // calculate number of permutations for each length i
        for (int i = 1; i <= n; i++) {
            int k = perm(10, i);
            
            // subtract numbers with leading zero's
            int sub = (i > 1 ? perm(9, i - 1) : 0);
            sum += k - sub;
        }
        return sum;
    }
};
