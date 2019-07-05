class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        part_sum = sum(A) // 3
        i = 0
        cur = 0
        for _ in range(3):
            if i >= len(A):
                return False
            while i < len(A) and cur != part_sum:
                cur += A[i]
                i += 1
            if cur != part_sum:
                return False
            cur = 0
        return True
