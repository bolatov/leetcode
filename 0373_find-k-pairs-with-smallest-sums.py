from heapq import heappop, heappush
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        for vi in nums1:
            for vj in nums2:
                heappush(heap, (vi+vj, vi, vj))
        ans = []
        while len(ans) < k and heap:
            _, vi, vj = heappop(heap)
            ans.append([vi, vj])
        return ans
