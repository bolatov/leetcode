class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        ans = []
        num = 0
        for i in A:
            num = (num << 1) | i
            ans.append(num % 5 == 0)
        return ans
