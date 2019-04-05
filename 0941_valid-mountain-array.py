class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3: return False
        be, en = 0, len(A)-1
        while be+1 <= en and A[be] < A[be+1]:
            be += 1
        while be <= en-1 and A[en-1] > A[en]:
            en -= 1
        return be == en and be > 0 and en < len(A)-1
