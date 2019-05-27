# By reading the solution...
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        bag = set(nums)
        ans = 0
        for num in nums:
            if num-1 in bag:
                continue
            x = num
            cnt = 0
            while x in bag:
                cnt += 1
                x += 1
            ans = max(cnt, ans)
        return ans
