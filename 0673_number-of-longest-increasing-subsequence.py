class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        size = len(nums)
        dp_len = [1 for _ in range(size)]
        dp_hit = [1 for _ in range(size)]
        maxlen = 0
        for j in range(size):
            for i in range(j):
                if nums[i] < nums[j]:
                    if dp_len[i] + 1 > dp_len[j]:
                        dp_len[j] = dp_len[i] + 1
                        dp_hit[j] = dp_hit[i]
                    elif dp_len[i] + 1 == dp_len[j]:
                        dp_hit[j] += dp_hit[i]
            maxlen = max(maxlen, dp_len[j])
        return sum([dp_hit[i] for i in range(size) if dp_len[i] == maxlen])
