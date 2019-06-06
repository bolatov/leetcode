class Solution:
    """
    @param nums:  an array of n integers
    @param target: a target
    @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
    """
    def threeSumSmaller(self, nums, target):
        # Write your code here
        if not nums:
            return 0
        nums.sort()
        ans = 0
        n = len(nums)
        for i in range(n):
            lo, hi = i + 1, n-1
            while lo < hi:
                sm = nums[i] + nums[lo] + nums[hi]
                if sm < target:
                    ans += hi - lo
                    lo += 1
                else:
                    hi -= 1
        return ans
