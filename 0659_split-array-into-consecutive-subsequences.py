from heapq import heappush, heappop
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        heap = []
        i = 0
        while i < len(nums):
            num = nums[i]
            if not heap:
                heappush(heap, [num, 1])
                i += 1
                continue
            top, cnt = heap[0]
            if top+1 == num:
                heappop(heap)
                heappush(heap, [num, cnt+1])
                i += 1
                continue
            if top == num:
                heappush(heap, [num, 1])
                i += 1
                continue
            if cnt >= 3:
                heappop(heap)
                continue
            else:
                return False
        return not heap or all([cnt >= 3 for _, cnt in heap])
