class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        elif len(nums) == 1:
            return nums[0]
        def helper(begin, end):
            if begin == end:
                return nums[begin]
            dp = [0 for _ in nums]
            dp[begin] = nums[begin]
            dp[begin+1] = max(nums[begin], nums[begin+1])
            for j in range(begin+2, end+1):
                dp[j] = max(dp[j-2] + nums[j], dp[j-1])
            return dp[end]
        max1 = helper(0, len(nums) - 2)
        max2 = helper(1, len(nums) - 1)
        return max(max1, max2)
