class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k <= 0:
            return []
        if k == 1:
            return nums
        ans = []
        deque = collections.deque([])
        for i in range(k-1):
            while deque and deque[-1][0] <= nums[i]:
                deque.pop()
            deque.append((nums[i], i))
        for i in range(k-1, len(nums)):
            if i - deque[0][1] >= k:
                deque.popleft()
            while deque and deque[-1][0] <= nums[i]:
                deque.pop()
            deque.append((nums[i], i))
            ans.append(deque[0][0])
        return ans
