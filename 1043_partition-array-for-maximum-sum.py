class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        n = len(A)
        dp = [0] * (n + 1)
        for i in range(1, n+1):
            aj = 0
            for j in range(1, K+1):
                aj = max(aj, A[i-j])
                if j <= i:
                    dp[i] = max(dp[i], dp[i-j] + aj * j)
        return dp[n]
