class Solution {
private:
    int solve(long long n) {
        if (n == 1) {
            return 0;
        }
        
        if (n % 2 == 0) {
            return 1 + solve(n / 2LL);
        }
        
        return 1 + min(solve(n + 1LL), solve(n - 1LL));
    }
public:
    int integerReplacement(int n) {
        return solve((long long) n);
    }
};
