class Solution:
    def queryString(self, S: str, N: int) -> bool:
        digits = [1 if s=='1' else 0 for s in S]
        nums = set()
        n = len(S)
        for i in range(n):
            num = 0
            for j in range(i, n):
                num |= digits[j]
                if 1 <= num <= N:
                    nums.add(num)
                elif num > N:
                    break
                num <<= 1
        return len(nums) == N
