class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        if (n==1) return A[0][0];
        int ans = INT_MAX;
        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int left = c-1 >= 0 ? A[r-1][c-1] : INT_MAX;
                int right = c+1 <  n ? A[r-1][c+1] : INT_MAX;
                A[r][c] += min(A[r-1][c], min(left, right));
                if (r+1 == n) ans = min(ans, A[r][c]);
            }
        }
        return ans;
    }
};
