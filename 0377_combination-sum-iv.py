class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        memo = {}
        def helper(t):
            if t < 0:
                return 0
            if t == 0:
                return 1
            if t not in memo:
                cur = 0
                for num in nums:
                    cur += helper(t-num)
                memo[t] = cur
            return memo[t]
        return helper(target)
