class Solution {
private:
    unordered_map<int, double> memo;
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        } else if (n == -1) {
            return 1 / x;
        } 
        if (!memo.count(n)) {
            memo[n] = myPow(x, n/2) * myPow(x, n/2) * myPow(x, n%2);
        }
        return memo[n];
    }
};
