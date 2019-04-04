class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        n = len(A)
        i, j = 0, n-1
        while i < j:
            while i < j and A[i]%2 == 0: i += 1
            while i < j and A[j]%2 == 1: j -= 1
            A[i], A[j] = A[j], A[i]
            i += 1
            j -= 1
        for i in range(1, n//2, 2):
            A[i], A[n-i-1] = A[n-i-1], A[i]
        return A
