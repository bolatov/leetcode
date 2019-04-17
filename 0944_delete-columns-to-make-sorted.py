class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        n, m = len(A), len(A[0])
        ans = 0
        for j in range(m):
            for i in range(1, n):
                if A[i-1][j] > A[i][j]:
                    ans += 1
                    break
        return ans
