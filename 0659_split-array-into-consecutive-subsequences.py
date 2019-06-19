from heapq import heappush, heappop
class Solution:
    # Maintain a heap with each node being an end of the sequence.
    # Each node in the heap holds a tuple with a tail element and count
    # of elements in that sequence.
    def isPossible(self, nums: List[int]) -> bool:
        heap = []
        i = 0
        while i < len(nums):
            num = nums[i]
            if not heap:
                # heap is empty, add the number and its count
                heappush(heap, [num, 1])
                i += 1
                continue
            top, cnt = heap[0]
            if top+1 == num:
                # current head can be augmented with a `num`
                heappop(heap)
                heappush(heap, [num, cnt+1])
                i += 1
                continue
            if top == num:
                # current had cannot be augmented, start a new sequence
                heappush(heap, [num, 1])
                i += 1
                continue
            # current head (sequence) cannot be augmented anymore,
            if cnt >= 3:  
                # it has more than 3 elements in the sequence,
                # remove it from the heap
                heappop(heap)
                continue
            else:
                # it has less than 3 elements, return False
                return False
        return not heap or all([cnt >= 3 for _, cnt in heap])
