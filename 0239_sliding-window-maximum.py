class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k <= 0:
            return []
        if k == 1:
            return nums
        ans = []
        deque = collections.deque([])
        for i in range(k-1):
            while deque and nums[deque[-1]] <= nums[i]:
                deque.pop()
            deque.append(i)
        for i in range(k-1, len(nums)):
            if i - deque[0] >= k:
                deque.popleft()
            while deque and nums[deque[-1]] <= nums[i]:
                deque.pop()
            deque.append(i)
            ans.append(nums[deque[0]])
        return ans
