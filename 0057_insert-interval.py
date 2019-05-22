class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]
        # Find an index where newInterval can be inserted
        lo, hi = 0, len(intervals)-1
        idx = len(intervals)
        while lo <= hi:
            mid = lo + (hi-lo) // 2
            imid = intervals[mid]
            if imid[0] == newInterval[0]:
                idx = mid
                break
            elif imid[0] > newInterval[0]:
                idx = mid
                hi = mid - 1
            else:
                lo = mid + 1

        intervals.insert(idx, newInterval)
        stack = collections.deque(reversed(intervals))
        ans = []
        while len(stack) > 1:
            i, j = stack.pop(), stack.pop()
            if i[0] <= j[0] <= i[1] or j[0] <= i[0] <= j[1]:
                stack.append([min(i[0], j[0]), max(i[1], j[1])])
            else:
                ans.append(i)
                stack.append(j)
        ans.append(stack.pop())
        return ans        
