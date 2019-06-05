class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return nums
        nums.sort()
        dp = [[val, -1, 1] for i,val in enumerate(nums)]
        maxidx = 0
        for i in range(len(dp)):
            for j in range(i):
                if dp[i][0] % dp[j][0] == 0 and dp[i][2] < dp[j][2] + 1:
                    dp[i] = [dp[i][0], j, dp[j][2] + 1]
            if dp[i][2] > dp[maxidx][2]:
                maxidx = i
        ans = []
        while maxidx >= 0:
            ans.append(dp[maxidx][0])
            maxidx = dp[maxidx][1]
        return ans
