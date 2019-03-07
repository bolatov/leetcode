class Solution {
private:
    int solve(vector<int>& vi, vector<int>& memo, int n) {
        if (n <= 0) {
            return 0;
        }
        if (memo[n] < INT_MAX) {
            return memo[n];
        }
        
        int minValue = INT_MAX;
        for (int i : vi) {
            if (n - i > 0) {
                minValue = min(minValue, solve(vi, memo, n - i) + 1);
            }
        }
        
        memo[n] = minValue;
        return minValue;
    }
public:
    int numSquares(int n) {
        vector<int> vi = {1};
        vector<int> memo(n + 1, INT_MAX);
        for (int i = 0; i < 4; i++) memo[i] = i;
        for (int i = 2; i * i <= n; i++) {
            vi.push_back(i * i);
            memo[i * i] = 1;
        }
        
        return solve(vi, memo, n);
    }
};
