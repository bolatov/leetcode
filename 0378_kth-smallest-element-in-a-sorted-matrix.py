class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        heap = []
        for row in matrix:
            for val in row:
                heapq.heappush(heap, val)
        while k > 1:
            top = heapq.heappop(heap)
            k -= 1
        return heapq.heappop(heap)
