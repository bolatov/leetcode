class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        n = len(A)
        i = n-2
        while i >= 0:
            if A[i] > A[i+1]:
                break
            i -= 1
        if i < 0:
            return A
        j = n-1
        idx = i+1
        while j > i:
            if A[i] > A[j] and A[j] >= A[idx]:
                idx = j
            j -= 1
        A[i], A[idx] = A[idx], A[i]
        return A
