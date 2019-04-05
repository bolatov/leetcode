class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        n = len(A)
        A.reverse()
        q = 0
        A[0] += K
        for i in range(n):
            A[i] += q
            q = A[i] // 10
            A[i] %= 10
        while q:
            A.append(q)
            q = A[-1] // 10
            A[-1] %= 10
        A.reverse()
        return A
