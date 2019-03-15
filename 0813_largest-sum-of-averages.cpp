class Solution {
private:
    vector<vector<double>> memo;
    double helper(vector<int>& A, int en, int K) {
        if (memo[en][K - 1] == 0.0) {
            double ans = 0;
            double sum = 0;
            int cnt = 0;
            for (int i = en; i >= 0; i--) {
                sum += A[i];
                cnt++;
                if (K > 1 && i > 0) {
                    double avg = (sum / (double) cnt) + helper(A, i - 1, K - 1);
                    ans = max(ans, avg);
                }
            }
            memo[en][K - 1] = K == 1 ? sum / (double) cnt : ans;
        }
        return memo[en][K - 1];
    }
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        memo = vector<vector<double>>(A.size(), vector<double>(K, 0.0));
        return helper(A, A.size() - 1, K);
    }
};
